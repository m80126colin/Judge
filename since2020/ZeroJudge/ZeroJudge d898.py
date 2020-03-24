'''
	@judge ZeroJudge
	@id d898
	@name Queue
	@source UVa 10128

	@tag Combinatorial Dynamic Programming

	@formula
		dp[length][observation from left][observation from right] = number of ways
		dp[n][i][j] =
			dp[n - 1][i - 1][j] +
			dp[n - 1][i][j - 1] +
			dp[n - 1][i][j] * (n - 2)
'''
from sys import stdin

N = 15
dp = [ [ [ 0 for _ in range(N + 1) ] for _ in range(N + 1) ] for _ in range(2) ]
dp[0][0][0] = dp[1][1][1] = 1
for n in range(2, N + 1):
	dp.append([ [
		dp[-1][i - 1][j] + dp[-1][i][j - 1] + (n - 2) * dp[-1][i][j]
			if i > 0 and j > 0 and i + j - 1 <= n
			else 0
	for j in range(N + 1) ] for i in range(N + 1) ])

def solve(n, p, r):
	if p + r - 1 > n or p < 0 or p > n or r < 0 or r > n:
		return 0
	return dp[n][p][r]

input()
for line in stdin:
	n, p, r = map(int, line.split())
	print(solve(n, p, r))