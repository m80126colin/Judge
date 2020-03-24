'''
	@judge ZeroJudge
	@id a388
	@name Critical Mass
	@source UVa 580

	@tag Dynamic Programming

	@formula
		@definition
			dp[n][length of tail U NOT EXCEED 2] = number of ways
			@backward
				dp[n][0] = sum(dp[n - 1])
				dp[n][i] = dp[n][i - 1]

		@definition
			ans[n] = 2 ** n - sum(dp[n - 1])
'''
from sys import stdin

N  = 30
dp = [ [ 0 for _ in range(3) ] ]
dp[0][0] = 1
for n in range(1, N + 1):
	res = [ sum(dp[-1]) ] + [ dp[-1][x - 1] for x in range(1, 3) ]
	dp.append(res)

ans = [ 2 ** n - sum(dp[n]) for n in range(N + 1) ]

for line in stdin:
	n = int(line)
	if n == 0:
		break
	print(ans[n])