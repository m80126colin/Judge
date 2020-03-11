'''
	@judge ZeroJudge
	@id a740
	@name 质因数之和

	@tag Integer Factorisation
'''
from math import sqrt, ceil
from sys import stdin

size  = ceil(sqrt(2000000000))
sieve = [ True ] * size

sieve[0] = sieve[1] = False
for x in range(2, ceil(sqrt(size)) + 1):
	if sieve[x] is True:
		for y in range(x << 1, size, x):
			sieve[y] = False

prime = [ x for x in range(2, size) if sieve[x] is True ]

def solve(n):
	ans = 0
	for p in prime:
		if n == 1:
			return ans
		if p * p > n:
			return ans + n
		while n % p == 0:
			ans += p
			n //= p
	return ans

for line in stdin:
	if line.strip() != '':
		print(solve(int(line)))