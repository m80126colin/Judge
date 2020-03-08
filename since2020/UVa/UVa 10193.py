'''
	@judge UVa
	@id 10193
	@name All You Need Is Love

	@tag Number Base Conversion, Greatest Common Divisor
'''
from sys import stdin
from math import gcd

def solve(n, s1, s2):
	g = gcd(int(s1, 2), int(s2, 2))
	return f'Pair #{n + 1}: All you need is love!' if g > 1 else f'Pair #{n + 1}: Love is not all you need!'

input()
print('\n'.join([ solve(n, *p) for n, p in enumerate(zip(*[iter(stdin)] * 2)) ]))