'''
	@judge ZeroJudge
	@id b369
	@name 因子和阶乘

	@tag Integer Factorisation
'''
from sys import stdin
from itertools import chain

size  = 30001
sieve = [ True ] * size
prime = [ 2, 3 ]

sieve[0] = sieve[1] = False
for x in chain(range(4, size, 2), range(9, size, 3)):
	sieve[x] = False
for x in range(5, size):
	if sieve[x]:
		prime.append(x)
		dx = (x << 2) + (x << 1)
		dy = 4 if x % 6 == 1 else 2
		for y in chain(range(x * x, size, dx), range((x + dy) * x, size, dx)):
			sieve[y] = False

def solve(n):
	ans = []
	for p in prime:
		if p > n:
			return ans
		cnt = 0
		pp = p
		while pp <= n:
			cnt += n // pp
			pp *= p
		ans.append(cnt)
	return ans

for line in stdin:
	n = int(line)
	print('{}!={}'.format(n, ' '.join([ str(x) for x in solve(n) ])))