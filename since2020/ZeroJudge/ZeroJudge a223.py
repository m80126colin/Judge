'''
	@judge ZeroJudge
	@id a233
	@name Power Strings
	@source UVa 10298

	@tag String Manipulation, Integer Factorisation, Search
'''
from sys import stdin
from math import ceil, sqrt
from itertools import chain

def test(s, x):
	n = len(s)
	t = s[:x] * (n // x)
	return s == t

def solve(s):
	n = len(s)
	divisor = [ x for x in range(1, ceil(sqrt(n)) + 1) if n % x == 0 ]
	for d in chain(divisor, map(lambda x: n // x, reversed(divisor))):
		if test(s, d):
			return n // d
	return 1

for line in stdin:
	if line.strip() != '.':
		print(solve(line.strip()))