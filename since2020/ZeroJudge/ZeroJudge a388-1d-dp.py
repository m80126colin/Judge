'''
	@judge ZeroJudge
	@id a388
	@name Critical Mass
	@source UVa 580

	@tag Linear Dynamic Programming

	@formula
		@definition
			dp[0] = 1
			dp[1] = 2
			dp[2] = 4
			dp[n] = dp[n - 1] + dp[n - 2] + dp[n - 3]

		@definition
			ans[n] = 2 ** n - dp[n]
'''
from sys import stdin

N  = 30
dp = [ 1, 2, 4 ]
for n in range(3, N + 1):
	dp.append(dp[-1] + dp[-2] + dp[-3])

ans = [ 2 ** n - dp[n] for n in range(N + 1) ]

for line in stdin:
	n = int(line)
	if n == 0:
		break
	print(ans[n])