'''
	@judge CodeForces
	@id 1328A
	@name Divisibility Problem
	@contest Codeforces Round #629 (Div. 3)

	@tag Modulus
'''
from sys import stdin

input()
for line in stdin:
	a, b = map(int, line.split())
	print((-a) % b)