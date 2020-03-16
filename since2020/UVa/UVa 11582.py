'''
	@judge UVa
	@id 11582
	@name Colossal Fibonacci Numbers!

	@tag Fibonacci Number, Congruence Modulus
'''
from sys import stdin
from collections import defaultdict
from math import gcd

cycle = [0]
for x in range(1, 1001):
	d = defaultdict()
	L = 0
	a, b = 0 % x, 1 % x
	while f'({a},{b})' not in d:
		L += 1
		d[f'({a},{b})'] = True
		a, b = b, (a + b) % x
	cycle.append(L)

fib = [0, 1]
for _ in range(2, max(cycle) + 1):
	fib.append(fib[-2] + fib[-1])

def solve(a, b, n):
	global fib, cycle
	if b == 0:
		return fib[1] % n
	A = a % cycle[n]
	if A == 0:
		return fib[0] % n
	B, C = b, 1
	while B > 0:
		if B & 1:
			C = (C * A) % cycle[n]
		A = (A * A) % cycle[n]
		B >>= 1
	return fib[C] % n

input()
for line in stdin:
	print(solve(*map(int, line.split())))