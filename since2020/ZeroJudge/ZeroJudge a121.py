'''
	@judge ZeroJudge
	@id a121
	@name 質數又來囉

	@tag Prime, Range Query
'''
from math import ceil
from itertools import chain
from collections import defaultdict
from sys import stdin

def LinearSieve(n):
	size  = n + 1
	prime = []
	sieve = [ True ] * size

	sieve[0] = sieve[1] = False
	for x in range(2, size):
		if sieve[x] is True:
			prime.append(x)
		for p in prime:
			if x * p >= size:
				break
			sieve[x * p] = False
			if x % p is 0:
				break
	
	return prime, sieve

size = 10001
prime, sieve = LinearSieve(size)

store = defaultdict()

def isPrime(n):
	if n < size:
		return sieve[n]
	if n in store:
		return store[n]
	for p in prime:
		if p * p > n:
			return True
		if n % p == 0:
			return False
	return True

def solve(a, b):
	ans = 0
	for x in [2, 3]:
		if a <= x and x <= b:
			ans += 1
	for n in chain(range(ceil((a - 5) / 6) * 6 + 5, b + 1, 6), range(ceil((a - 1) / 6) * 6 + 1, b + 1, 6)):
		store[n] = isPrime(n)
		if store[n]:
			ans += 1
	return str(ans)

print('\n'.join([ solve(*map(int, line.split())) for line in stdin ]))