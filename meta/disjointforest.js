const _ = require('lodash')

const find = (table, x) => {
  if (table[x] != x)
    table[x] = find(table, table[x])
  return table[x]
}

const union = (table, edge) => {
  const a = table[edge[0]]
  const b = table[edge[1]]
  if (a != b)
    table[b] = find(table, a)
}

const grouping = (nodes, edges) => {
  const total_nodes = _.chain(nodes)
    .concat(_.flatten(edges))
    .uniqBy()
    .value()
  const table = _.chain(total_nodes).map(node => [node, node]).fromPairs().value()
  _.map(edges, edge => union(table, edge))
  _.map(nodes, node => find(table, node))
  return table
}

module.exports = {
  grouping
}