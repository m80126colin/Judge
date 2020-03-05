'''
	CodeForces 160A
	Twins

	Tags: Greedy
'''
from functools import reduce

def solve(p, curr):
	remain, num = p
	if remain < 0:
		return p
	return (remain - curr, num + 1)

input()
coins = sorted(map(int, input().split()), key=lambda x: -x)

s = sum(coins)
_, ans = reduce(solve, coins, (s // 2, 0))

print(ans)