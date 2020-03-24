'''
	@judge ZeroJudge
	@id c061
	@name Binomial Showdown
	@source UVa 530

	@tag Combinatorics
'''
from sys import stdin
from functools import reduce

def prod(a, b):
	return a * b

def solve(n, m):
	m = min(m, n - m)
	if m == 0:
		return 1
	return reduce(prod, map(lambda x: n - x, range(m))) // reduce(prod, range(1, m + 1))

for line in stdin:
	n, m = map(int, line.split())
	if n == 0 and m == 0:
		break
	print(solve(n, m))