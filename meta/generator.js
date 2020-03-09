const _     = require('lodash')
const path  = require('path')
const util  = require('util')
const globO = require('glob')
const fs    = require('fs')

const config = require('./config')
const forest = require('./disjointforest')
const glob   = util.promisify(globO)

const root = path.join(__dirname, '..')
/**
 * @param {string} data source code
 * @param {string} ext extension of file
 */
const parseAttr = (data, ext) => {
  const match = data.match(config.getRegex(ext))
  // no comment
  if (_.isNull(match))
    return []
  // parse attribute
  const attr = _.chain(match[1])
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
  return attr
}
/**
 * @param {string} file file name
 * @returns {{
 *    isnew?   : boolean,
 *    problem? : string,
 *    judge?   : string,
 *    id?      : string,
 *    name?    : string,
 *    source?  : string[],
 *    contest? : string[],
 *    tag?     : string[]
 * }}
 */
const parser = async file => {
  const data = await fs.promises.readFile(file, 'utf-8')
  const attr = parseAttr(data, path.extname(file))
  // empty comment
  if (attr.length === 0)
    return undefined
  // process tag
  const result = _.chain(attr)
    .groupBy('tag')
    .mapValues((ps, key) => {
      if (key !== 'tag')
        return config.getMerge(key, _.map(ps, 'value'))
      const vals = _.chain(ps)
        .flatMap(p => _.split(p.value, ','))
        .map(_.trim)
        .value()
      return config.getMerge(key, vals)
    })
    .thru(obj => _.merge(obj, obj.id ? {} : { id: obj.name }))
    .thru(obj => _.merge(obj, {
      isnew: /since2020/u.test(file),
      problem: `${obj.judge} ${obj.id}`
    }))
    .value()
  return result
}

const execute = async () => {
  // parse all name of files
  const files = await glob(`${root}/@(before2020|since2020)/**/*.*`)
  // parse all files with corresponding ext name
  const promises = _.chain(files)
    .filter(file => config.isExt(path.extname(file)))
    .map(parser)
    .value()
  const rows = await Promise.all(promises)
  // merge with identical (judge, id) = problem
  const group = _.chain(rows)
    .compact()
    .groupBy('problem')
    .mapValues((objs, key) => {
      const taglist = config.getMerge('taglist', _.map(objs, obj => _.pick(obj, ['isnew', 'tag'])))
      const source  = config.getMerge('source',  _.map(objs, 'source'))
      const contest = config.getMerge('contest', _.map(objs, 'contest'))
      const prob = _.chain(objs)
        .flatMap(obj => _.chain(obj).omit(['isnew', 'tag', 'source', 'contest']).toPairs().value())
        .groupBy(0)
        .mapValues((ps, key) => config.getMerge(key, _.map(ps, 1)))
        .value()
      return {
        source,
        contest,
        taglist,
        problist: [ prob ]
      }
    })
    .value()
  // merge with source
  const edges   = _.flatMap(group, (g, key) => _.map(g.source, src => [src, key]))
  const mapping = forest.grouping(_.keys(group), edges)
  const result  = _.chain(group)
    .map((g, key) => [mapping[key], g])
    .groupBy(0)
    .map(gs => _.chain(gs)
      .map(1)
      .flatMap(g => _.toPairs(g))
      .groupBy(0)
      .mapValues((ps, key) => config.getMerge(key, _.map(ps, 1)))
      .value())
    .value()
  // output
  await fs.promises.mkdir(`${root}/dist`, { recursive: true })
  await fs.promises.writeFile(`${root}/dist/data.json`, JSON.stringify(result))
}
execute()