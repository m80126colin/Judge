'''
	@judge UVa
	@id 10090
	@name Marbles

	@tag Extended Euclidean Algorithm, Greatest Common Divisor
'''
from sys import stdin
from math import ceil, floor

def ExtGCD(a, b):
	if a % b == 0:
		return (b, 0, 1)
	g, x, y = ExtGCD(b, a % b)
	return (g, y, x - (a // b) * y)

def solve(n, p1, p2):
	cx, nx = p1
	cy, ny = p2
	g, x, y = ExtGCD(nx, ny)
	da, db = ceil(-x * n / ny), floor(y * n / nx)
	if n % g != 0 or da > db:
		return 'failed'
	ax, ay = min(map(lambda d: ((x * n + d * ny) // g, (y * n - d * nx) // g), [da, db]), key=lambda p: p[0] * cx + p[1] * cy)
	return f'{ax} {ay}'

def testcase(n, p1, p2):
	return int(n), tuple(map(int, p1.split())), tuple(map(int, p2.split()))

for test in zip(*[ iter(stdin) ] * 3):
	print(solve(*testcase(*test)))