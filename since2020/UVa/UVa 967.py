'''
	@judge UVa
	@id 967
	@name Circular

	@tag Prime, Range Query
'''
from sys import stdin
from itertools import accumulate
from math import sqrt

N = 1000000
sieve = [ 1 ] * N

sieve[0] = sieve[1] = 0
for x in range(2, int(sqrt(N) + 0.01) + 1):
	if sieve[x]:
		for y in range(x * x, N, x):
			sieve[y] = 0

def circle(n):
	m = str(n) * 2
	L = len(m) // 2
	return all(map(lambda x: sieve[int(m[x:x+L])], range(L)))

dp = list(accumulate([ 1 if circle(x) else 0 for x in range(N) ]))

def solve(a, b):
	res = dp[b] - dp[a - 1]
	if res == 0:
		return 'No Circular Primes.'
	if res == 1:
		return '1 Circular Prime.'
	return f'{res} Circular Primes.'

for line in stdin:
	if line.strip() != '-1':
		print(solve(*map(int, line.split())))