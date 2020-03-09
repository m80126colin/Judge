const _ = require('lodash')

const commentRegex = {
  cpp: /^\s*\/\*+\s*((?:.|\r|\n)+?)\s*\*+\//u,
  py:  /^\s*'''\s*((?:.|\r|\n)+?)\s*'''/u,
  hs:  /^\s*\{-+\s*((?:.|\r|\n)+?)\s*-+\}/u
}

const mappingRegex = {
  '.cpp': 'cpp',
  '.cc': 'cpp',
  '.py': 'py',
  '.hs': 'hs'
}

const mergeAttr = {
  headMerge:  vals => _.head(vals),
  arrayMerge: vals => _.chain(vals).flatten().uniqBy().compact().value(),
  tagMerge:   vals => _.chain(vals)
    .flatten()
    .groupBy('isnew')
    .map(objs => {
      return {
        isnew: _.chain(objs).head().get('isnew').value(),
        tag: _.chain(_.map(objs, 'tag')).flatten().uniqBy().compact().value()
      }
    })
    .value()
}

const mappingAttr = {
  problem:  'headMerge',
  judge:    'headMerge',
  id:       'headMerge',
  name:     'headMerge',
  source:   'arrayMerge',
  contest:  'arrayMerge',
  tag:      'arrayMerge',
  problist: 'arrayMerge',
  taglist:  'tagMerge'
}

const isExt    = ext  => ext in mappingRegex
const getRegex = ext  => commentRegex[ mappingRegex[ext] ]
const attrType = attr => mappingAttr[attr]
const getMerge = (attr, vals) => mergeAttr[ mappingAttr[attr] ](vals)

module.exports = {
  isExt,
  attrType,
  getMerge,
  getRegex
}