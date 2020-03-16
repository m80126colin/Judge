'''
	@judge UVa
	@id 12068
	@name Harmonic Mean

	@tag Greatest Common Divisor
'''
from sys import stdin
from math import gcd
from functools import reduce

input()
for t, line in enumerate(stdin):
	n, *arr = map(int, line.split())
	A = reduce(lambda p, x: p * x, arr)
	B = sum(map(lambda x: A // x, arr))
	g = gcd(A * n, B)
	print(f'Case {t + 1}: {A * n // g}/{B // g}')