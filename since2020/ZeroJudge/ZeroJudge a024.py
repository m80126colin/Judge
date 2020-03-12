'''
	@judge ZeroJudge
	@id a024
	@name 最大公因數(GCD)

	@tag Greatest Common Divisor
'''
from sys import stdin
from math import gcd

for line in stdin:
	print(gcd(*map(int, line.split())))