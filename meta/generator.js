const _     = require('lodash')
const path  = require('path')
const util  = require('util')
const globO = require('glob')
const fs    = require('fs')
const ghpages = require('gh-pages')

const glob = util.promisify(globO)

const root = path.join(__dirname, '..')

const regex = {
  cpp: /^\s*\/\*+\s*((?:.|\r|\n)+?)\s*\*+\//u,
  py:  /^\s*'''\s*((?:.|\r|\n)+?)\s*'''/u,
  hs:  /^\s*\{-+\s*((?:.|\r|\n)+?)\s*-+\}/u
}

const lookup = {
  '.cpp': 'cpp',
  '.cc': 'cpp',
  '.py': 'py',
  '.hs': 'hs'
}

const merger = (key, vals) => {
  switch (key) {
    case 'judge':
    case 'id':
    case 'name':
      return _.head(vals)
    case 'contest':
    case 'tag':
      return _.chain(vals).flatten().uniqBy().value()
  }
}

const parser = async file => {
  const ext   = path.extname(file)
  const data  = await fs.promises.readFile(file, 'utf-8')
  const match = data.match(regex[lookup[ext]])
  if (_.isNull(match))
    return undefined
  const temp = _.chain(match[1])
    .split(/\r?\n/)
    .map(line => {
      const group = line.match(/@(\S+)\s+(.+)/u)
      if (_.isNull(group))
        return undefined
      return {
        tag: group[1],
        value: _.trim(group[2])
      }
    })
    .compact()
    .value()
  if (temp.length === 0)
    return undefined
  const result = _.chain(temp)
    .groupBy('tag')
    .mapValues((ps, key) => {
      if (key !== 'tag')
        return merger(key, _.map(ps, 'value'))
      const vals = _.chain(ps)
        .flatMap(p => _.split(p.value, ','))
        .map(_.trim)
        .uniqBy()
        .value()
      return merger(key, vals)
    })
    .thru(obj => _.merge(obj, obj.id ? {} : { id: obj.name }))
    .value()
  return result
}

const execute = async () => {
  const files = await glob(`${root}/@(before2020|since2020)/**/*.*`)
  const promises = _.chain(files)
    .filter(file => lookup[path.extname(file)])
    .map(parser)
    .value()
  const temp = await Promise.all(promises)
  const result = _.chain(temp)
    .compact()
    .groupBy(obj => `(${obj.judge},${obj.id})`)
    .map(objs => _.chain(objs)
      .flatMap(obj => _.toPairs(obj))
      .groupBy(0)
      .mapValues((ps, key) => merger(key, _.map(ps, 1)))
      .value())
    .value()
  await fs.promises.mkdir(`${root}/dist`, { recursive: true })
  await fs.promises.writeFile(`${root}/dist/data.json`, JSON.stringify(result))
}
execute()