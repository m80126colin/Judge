'''
	@judge ZeroJudge
	@id e577
	@name Smith Numbers
	@source UVa 10042

	@tag Prime, Integer Factorisation, Digit Sum
'''
from sys import stdin
from math import sqrt
from itertools import count, chain, zip_longest

def digit_sum(n):
	res = 0
	while n > 0:
		res += n % 10
		n //= 10
	return res

N  = 10 ** 9
NN = int(sqrt(N) + 0.01)
sieve = [ 0, 0 ] + [ 1 ] * (NN - 2)
prime = [ (2, 2), (3, 3) ]
for x in chain(range(4, NN, 2), range(9, NN, 3)):
	sieve[x] = 0
for x in chain(*zip_longest(range(5, NN, 6), range(7, NN, 6))):
	if x is None or sieve[x] == 0:
		continue
	prime.append((x, digit_sum(x)))
	for y in range(x * x, NN, x):
		sieve[y] = 0

def isp(n):
	if n < NN:
		return sieve[n]
	for x, _ in prime:
		if x * x > n:
			return True
		if n % x == 0:
			return False
	return True

def factor(n):
	res = 0
	for x, d in prime:
		if x * x > n:
			break
		cnt = 0
		while n % x == 0:
			cnt += 1
			n //= x
		if cnt > 0:
			res += cnt * d
	if n > 1:
		return res + digit_sum(n)
	return res

def solve(n):
	for x in count(n + 1):
		if isp(x) == False and factor(x) == digit_sum(x):
			return x

input()
for line in stdin:
	print(solve(int(line)))