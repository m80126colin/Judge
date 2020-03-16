'''
	@judge ZeroJudge
	@id e656
	@name Ingenuous Cubrency
	@source UVa 11137

	@tag Change-making
'''
from sys import stdin

N = 10000
dp = [ 0 ] * N

dp[0] = 1
for c in map(lambda x: x ** 3, range(1, 214)):
	for pos in range(N - c):
		dp[pos + c] += dp[pos]

for line in stdin:
	n = int(line)
	print(dp[n])