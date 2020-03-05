'''
	CodeForces 1305D, Ozon Tech Challenge 2020
	Kuroni and the Celebration

	Tags: Ad-hoc, Simulation
'''
from sys import stdout
from itertools import chain, groupby
from collections import Counter

gkey = lambda p: p[0]

def delNode(node, adj, leaves):
	target = next(iter(adj[node]))
	adj[node].remove(target)
	adj[target].remove(node)
	if len(adj[target]) == 1:
		leaves.append(target)

def solve(edges):
	groups = groupby(sorted(chain(*map(lambda p: [p, (p[1], p[0])], edges)), key=gkey), gkey)
	adj    = dict(map(lambda ps: (ps[0], set(map(lambda p: p[1], ps[1]))), groups))
	leaves = [ k for k, v in adj.items() if len(v) == 1 ]
	while len(leaves) > 1:
		u = leaves.pop()
		v = leaves.pop()
		print(f'? {u} {v}')
		stdout.flush()
		ans = input()
		if ans == u or ans == v:
			return ans
		delNode(u, adj, leaves)
		delNode(v, adj, leaves)
	return leaves[0]

n = int(input())
edges = [ tuple(input().split()) for _ in range(n - 1) ]

print('! {}'.format(solve(edges)))