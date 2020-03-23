'''
	@judge CodeForces
	@id 1326C
	@name Permutation Partitions
	
	@tag Math, Combinatorics
'''
from functools import reduce

MOD = 998244353

n, k = map(int, input().split())
arr = list(map(int, input().split()))

m = n - k + 1
bs = list(map(lambda p: p[0], filter(lambda p: p[1] >= m, enumerate(arr))))

it = iter(bs)
next(it)
ans = reduce(lambda s, p: s * (p[1] - p[0]) % MOD, zip(iter(bs), it), 1)

print((n + m) * k // 2, ans)