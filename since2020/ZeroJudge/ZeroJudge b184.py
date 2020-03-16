'''
	@judge ZeroJudge
	@id b184
	@name 5. 裝貨櫃問題

	@tag 0/1 Knapsack
'''
from sys import stdin

N = 101

def solve(pair):
	dp = [ -1 ] * N
	dp[0] = 0
	for v, c in pair:
		for x in range(N - v - 1, -1, -1):
			if dp[x] >= 0:
				dp[x + v] = max(dp[x + v], dp[x] + c)
	return max(dp)

for line in stdin:
	n = int(line)
	pair = [ tuple(map(int, input().split())) for _ in range(n) ]
	print(solve(pair))