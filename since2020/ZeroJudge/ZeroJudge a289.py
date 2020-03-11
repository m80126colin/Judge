'''
	@judge ZeroJudge
	@id a289
	@name Modular Multiplicative Inverse

	@tag Extended Euclidean Algorithm, Congruence Modulus
'''
from sys import stdin

def ExtGCD(a, b):
	if a % b is 0:
		return (b, 0, 1)
	g, x, y = ExtGCD(b, a % b)
	return (g, y, x - y * (a // b))

def solve(a, n):
	g, x, y = ExtGCD(a, n)
	b = (x + n) % n
	return 'No Inverse' if g is not 1 or b is 0 else b

for line in stdin:
	print(solve(*map(int, line.split())))