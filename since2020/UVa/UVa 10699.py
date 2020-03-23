'''
	@judge UVa
	@id 10699
	@name Count the factors

	@tag Dynamic Programming, Integer Factorisation
'''
from sys import stdin
from itertools import chain, zip_longest

N = 1000001
sieve = [ 0 ] * N
for x in chain(range(2, N, 2), range(3, N, 3)):
	sieve[x] += 1
for x in chain(*zip_longest(range(5, N, 6), range(7, N, 6))):
	if x is None or sieve[x] > 0:
		continue
	for y in range(x, N, x):
		sieve[y] += 1

for line in stdin:
	n = int(line)
	if n != 0:
		print(n, ':', sieve[n])