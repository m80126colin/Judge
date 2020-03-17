'''
	@judge ZeroJudge
	@id e552
	@name Sum of Consecutive Prime Numbers
	@source UVa 1210

	@tag Prime, Range Query, Dynamic Programming
'''
from sys import stdin
from math import sqrt
from itertools import accumulate, chain, zip_longest

N   = 10001
sqN = int(sqrt(N) + 0.01)
sieve = [ 0, 0 ] + [ 1 ] * (N - 2)

for x in chain(range(4, N, 2), range(9, N, 3)):
	sieve[x] = 0
for x in chain(*zip_longest(range(5, sqN + 1, 6), range(7, sqN + 1, 6))):
	if x is not None and sieve[x]:
		for y in range(x * x, N, x):
			sieve[y] = 0

prefix = list(accumulate([ x for x in range(N) if sieve[x] ]))
for x in range(1, len(prefix)):
	if prefix[x] < N:
		sieve[prefix[x]] += 1
	for y in range(x - 1):
		if prefix[x] - prefix[y] < N:
			sieve[prefix[x] - prefix[y]] += 1

for line in stdin:
	n = int(line)
	if n != 0:
		print(sieve[n])