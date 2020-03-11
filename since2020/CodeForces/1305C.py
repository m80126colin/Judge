'''
	@judge CodeForces
	@id 1305C
	@name Kuroni and Impossible Calculation
	@contest Ozon Tech Challenge 2020

	@tag Math, Modulus
'''
from collections import Counter
from itertools import combinations
from functools import reduce

def solve(n, m, arr):
	if n > m:
		return 0
	check = any(map(lambda x: x > 1, Counter(map(lambda x: x % m, arr)).values()))
	if check:
		return 0
	res = reduce(lambda cum, p: (cum * abs(p[0] - p[1])) % m, combinations(arr, 2), 1)
	return res

n, m = map(int, input().split())
arr = list(map(int, input().split()))
print(solve(n, m, arr))