'''
	@judge UVa
	@id 147
	@name Dollars

	@tag Change-making
'''
from sys import stdin

N = 30001
coin = [5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000]
dp = [ 0 ] * N

dp[0] = 1
for c in coin:
	for pos in range(N - c):
		dp[pos + c] += dp[pos]

for line in stdin:
	n = int(float(line) * 100 + 0.01)
	if n == 0:
		break
	print('{:>6}{:>17}'.format(line.strip(), dp[n]))