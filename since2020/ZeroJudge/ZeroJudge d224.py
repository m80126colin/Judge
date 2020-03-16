'''
	@judge ZeroJudge
	@id d224
	@name Counting Solutions to an Integral Equation
	@source UVa 11296

	@tag Change-making, Dynamic Programming
'''
from sys import stdin

N  = 1000001
dp = [ 1 ] * N
for _ in range(2):
	for x in range(N):
		if x + 2 < N:
			dp[x + 2] += dp[x]

for line in stdin:
	print(dp[int(line)])