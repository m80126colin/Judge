'''
	CodeForces 479C
	Exams

	Tags: Sortings, Greedy
'''
from sys import stdin

def solve(ls):
	ans = ls[0][1]
	for (a, b) in ls:
		ans = b if ans <= b else a
	return ans

n     = int(input())
exams = list(tuple(map(int, line.split())) for line in stdin.readlines())
res   = solve(sorted(exams, key = lambda p: p[0] * 1000000000 + p[1]))

print(res)