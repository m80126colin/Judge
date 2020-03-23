'''
	@judge UVa
	@id 10066
	@name The Twin Towers

	@tag Longest Common Subsequence
'''
from sys import stdin

dp = [ [ 0 ] * 101 for _ in range(101) ]

t = 1
for x, a, b in zip(*[ iter(stdin) ] * 3):
	n, m = map(int, x.split())
	xs = list(map(int, a.split()))
	ys = list(map(int, b.split()))
	for x in range(1, n + 1):
		for y in range(1, m + 1):
			if xs[x - 1] == ys[y - 1]:
				dp[x][y] = dp[x - 1][y - 1] + 1
			else:
				dp[x][y] = max(dp[x - 1][y], dp[x][y - 1])
	print('Twin Towers #{}\nNumber of Tiles : {}\n'.format(t, dp[n][m]))
	t += 1