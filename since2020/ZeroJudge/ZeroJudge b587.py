'''
	@judge ZeroJudge
	@id b587
	@name Tri Tiling
	@source UVa 10918

	@tag Linear Dynamic Programming

	@formula
		dp[n]
		= dp[n - 1] + sum(dp) * 2
		= 4 * dp[n - 1] - dp[n - 2]
'''
from sys import stdin

N = 15
dp = [ 1, 3 ]
for _ in range(2, N + 1):
	dp.append((dp[-1] << 2) - dp[-2])

def solve(n):
	if n % 2:
		return 0
	return dp[n >> 1]

for line in stdin:
	n = int(line)
	if n < 0:
		break
	print(solve(n))