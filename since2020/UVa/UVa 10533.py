'''
	@judge UVa
	@id 10533
	@name Digit Primes

	@tag Digit Sum, Prime, Range Query
'''
from sys import stdin
from itertools import accumulate

def digit_sum(n):
	ans = 0
	while n > 0:
		ans += n % 10
		n //= 10
	return ans

N = 1000000
sieve = [ 1 ] * N

sieve[0] = sieve[1] = 0
for x in range(2, 1000):
	if sieve[x]:
		for y in range(x * x, N, x):
			sieve[y] = 0
for x in range(N - 1, -1, -1):
	if sieve[x]:
		sieve[x] = sieve[digit_sum(x)]
sieve = list(accumulate(sieve))

def solve(a, b):
	return sieve[b] - sieve[a - 1]

input()
for line in stdin:
	print(solve(*map(int, line.split())))