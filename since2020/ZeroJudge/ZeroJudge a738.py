'''
	@judge ZeroJudge
	@id a738
	@name 最大公约数

	@tag Greatest Common Divisor
'''
from sys import stdin
from math import gcd

for line in stdin:
	if line.strip() != '':
		print(gcd(*map(int, line.split())))