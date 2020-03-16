'''
	@judge ZeroJudge
	@id d133
	@name Let Me Count The Ways
	@source UVa 357

	@tag Change-making
'''
from sys import stdin

N = 30001
coin = [1, 5, 10, 25, 50]
dp = [ 0 ] * N

dp[0] = 1
for c in coin:
	for pos in range(N - c):
		dp[pos + c] += dp[pos]

for line in stdin:
	n = int(line)
	res = dp[n]
	if res != 1:
		print(f'There are {res} ways to produce {n} cents change.')
	else:
		print(f'There is only 1 way to produce {n} cents change.')