'''
	@judge ZeroJudge
	@id a388
	@name Critical Mass
	@source UVa 580

	@tag Dynamic Programming, Combinatorics

	@formula
		@definition
			dp[n][max length of U][length of tail U] = number of ways

			@backward
				dp[n][i][0] = sum([ dp[n - 1][i][j] for j in range(n + 1) ])
				dp[n][i][j] = 0                                             if j > i
				dp[n][i][j] = dp[n - 1][i][j - 1] + dp[n - 1][i - 1][j - 1] if j == i
				dp[n][i][j] = dp[n - 1][i][j - 1]                           if j < i
			@forward (j <= i)
				dp[n][i][j] -> dp[n + 1][i][0]
				dp[n][i][j] -> dp[n + 1][i][j + 1]     if j < i
				dp[n][i][j] -> dp[n + 1][i + 1][j + 1] if j == i

		@definition
			ans[n] = sum([ dp[n][i][j] for j in range(n + 1) for i in range(3, n + 1) ])
'''
from sys import stdin

N  = 30
dp = [ [ [ 0 for _ in range(N + 1) ] for _ in range(N + 1) ] ]
dp[0][0][0] = 1
for n in range(1, N + 1):
	res = [ [ 0 for _ in range(N + 1) ] for _ in range(N + 1) ]
	for i in range(n):
		for j in range(n):
			if dp[-1][i][j]:
				res[i][0] += dp[-1][i][j]
				res[max(i, j + 1)][j + 1] += dp[-1][i][j]
	dp.append(res)

ans = [ sum([ dp[n][i][j] for j in range(n + 1) for i in range(3, n + 1) ]) for n in range(N + 1) ]

for line in stdin:
	n = int(line)
	if n == 0:
		break
	print(ans[n])