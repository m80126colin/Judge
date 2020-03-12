'''
	@judge ZeroJudge
	@id d693
	@name 最小公倍數

	@tag Greatest Common Divisor
'''
from sys import stdin
from math import gcd
from functools import reduce

for _, line in zip(*[ iter(stdin) ] * 2):
	print(reduce(lambda a, b: a * b // gcd(a, b), map(int, line.split()), 1))