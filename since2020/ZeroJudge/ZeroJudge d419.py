'''
	@judge ZeroJudge
	@id d419
	@name Factorial Factors
	@source UVa 884

	@tag Factorial, Dynamic Programming
'''
from sys import stdin
from itertools import chain, zip_longest

N = 1000001
dp = [ 0, 0 ] + [ 1 ] * (N - 2)
for x in range(2, N):
	if dp[x] == 1:
		for y in range(2, N // x + 1):
			if x * y < N:
				dp[x * y] = dp[x] + dp[y]
for x in range(N - 1):
	dp[x + 1] += dp[x]

for line in stdin:
	print(dp[int(line)])