'''
	@judge ZeroJudge
	@id e655
	@name Less Prime
	@source UVa 10852

	@tag Prime, Modulus, Binary Search
'''
from sys import stdin
from itertools import count, chain, zip_longest
from bisect import bisect_right

N = 10001
sieve = [ 0, 0 ] + [ 1 ] * (N - 2)
prime = [ 2, 3 ]
for x in chain(range(4, N, 2), range(9, N, 3)):
	sieve[x] = 0
for x in chain(*zip_longest(range(5, N, 6), range(7, N, 6))):
	if x is None or sieve[x] == 0:
		continue
	prime.append(x)
	for y in range(x * x, N, x):
		sieve[y] = 0

def solve(n):
	return prime[bisect_right(prime, n // 2)]

input()
for line in stdin:
	n = int(line)
	print(solve(n))