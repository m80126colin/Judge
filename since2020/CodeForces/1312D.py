'''
	@judge CodeForces
	@id 1312D
	@name Count the Arrays

	@tag Combinatorics, Congruence Modulus
'''
from sys import stdin

def ExtGCD(a, b):
	if a % b == 0:
		return (b, 0, 1)
	g, x, y = ExtGCD(b, a % b)
	return (g, y, x - (a // b) * y)

def inv(a, m):
	_, _, y = ExtGCD(m, a)
	return (y + m) % m

def modComb(a, b, m):
	ans = 1
	for x in range(1, min(b, a - b) + 1):
		ans = (ans * (a - x + 1)) % m
		ans = (ans * inv(x, m)) % m
	return ans

def modPow(a, b, m):
	ans = 1
	aa = a
	while b > 0:
		if b & 1:
			ans = (ans * aa) % m
		aa = (aa * aa) % m
		b >>= 1
	return ans

def solve(n, m):
	MOD = 998244353 
	ax = modComb(m, n - 1, MOD) * (n - 2) % MOD
	ay = modPow(2, n - 3, MOD)
	return ax * ay % MOD

for line in stdin:
	n, m = map(int, line.split())
	print(solve(n, m))