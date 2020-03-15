'''
	@judge CodeForces
	@id 1325C
	@name Ehab and Path-etic MEXs
	@contest Codeforces Round #628

	@tag Greedy, Graph Theory
'''
from sys import stdin
from collections import Counter

def solve(n, es):
	label = [ -1 ] * (n - 1)
	c = Counter([ x for p in es for x in p ])
	m = len(list(filter(lambda x: x == 1, c.values())))
	L, R = 0, m
	for idx, uv in enumerate(es):
		u, v = uv
		if c[u] == 1 or c[v] == 1:
			label[idx] = L
			L += 1
		else:
			label[idx] = R
			R += 1
	print('\n'.join([ str(l) for l in label ]))

n  = int(input())
es = [ tuple(map(int, line.split())) for line in stdin ]
solve(n, es)