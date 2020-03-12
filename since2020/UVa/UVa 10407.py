'''
	@judge UVa
	@id 10407
	@name Simple division

	@tag Greatest Common Divisor
'''
from sys import stdin
from math import gcd
from functools import reduce

def solve(arr):
	it = iter(arr)
	next(it)
	ans = reduce(lambda p, a: gcd(p, a), map(lambda p: p[0] - p[1], zip(iter(arr), it)))
	return abs(ans)

for line in stdin:
	arr = list(map(int, line.split()))[:-1]
	if len(arr) > 0:
		print(solve(arr))