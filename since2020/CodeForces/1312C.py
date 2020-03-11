'''
	@judge CodeForces
	@id 1312C
	@name Adding Powers

	@tag Greedy, Number Base Conversion
'''
from math import ceil, log
from sys import stdin

def toKBase(n, k, d):
	for _ in range(d + 1):
		yield n % k
		n //= k

def solve(arr, k):
	if max(arr) == 0:
		return True
	digit = ceil(log(max(arr), k))
	return all(map(lambda ls: sum(ls) <= 1, zip(*map(lambda n: tuple(toKBase(n, k, digit)), arr))))

input()
for fst, nxt in zip(*[ iter(stdin) ] * 2):
	_, k = map(int, fst.split())
	arr  = list(map(int, nxt.split()))
	print('YES' if solve(arr, k) else 'NO')