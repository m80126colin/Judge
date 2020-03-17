'''
	@judge ZeroJudge
	@id e530
	@name Prime Gap
	@source UVa 1644

	@tag Prime, Binary Search
'''
from sys import stdin
from bisect import bisect_left
from math import sqrt

N = 1299710
sieve = [ 1 ] * N

sieve[0] = sieve[1] = 0
for x in range(2, int(sqrt(N) + 0.01) + 1):
	if sieve[x]:
		for y in range(x * x, N, x):
			sieve[y] = 0

prime = [ x for x in range(N) if sieve[x] ]

def solve(k):
	pos = bisect_left(prime, k)
	if prime[pos] == k:
		return 0
	return prime[pos] - prime[pos - 1]

for line in stdin:
	k = int(line)
	if k != 0:
		print(solve(k))