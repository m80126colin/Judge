'''
	CodeForces 545C
	Woodcutters

	Tags: Greedy
'''
from sys import stdin
from functools import reduce

def solve(p, segs):
	left, ans = p
	(_, h), (right, _) = segs
	if h <= left:
		return (right, ans + 1)
	if h <= right:
		return (right - h, ans + 1)
	return (right, ans)

n = int(input())
trees = sorted([ tuple(map(int, line.split())) for line in stdin.readlines() ], key=lambda p: p[0])

if n <= 2:
	print(n)
else:
	segments = list(map(lambda p: (p[1][0] - p[0][0] - 1, p[1][1]), zip(trees, trees[1:])))
	_, ans = reduce(solve, zip(segments, segments[1:]), (segments[0][0], 2))
	print(ans)