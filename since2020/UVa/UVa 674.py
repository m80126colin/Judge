'''
	@judge UVa
	@id 674
	@name Coin Change

	@tag Change-making
'''
from sys import stdin

N = 7490
coin = [1, 5, 10, 25, 50]
dp = [ 0 ] * N

dp[0] = 1
for c in coin:
	for pos in range(N - c):
		dp[pos + c] += dp[pos]

for line in stdin:
	n = int(line)
	print(dp[n])