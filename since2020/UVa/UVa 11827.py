'''
	@judge UVa
	@id 11827
	@name Maximum GCD

	@tag Greatest Common Divisor
'''
from sys import stdin
from itertools import combinations
from math import gcd

input()
for line in stdin:
	print(max(map(lambda p: gcd(*p), combinations(map(int, line.split()), 2))))