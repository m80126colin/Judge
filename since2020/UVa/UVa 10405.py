'''
	@judge UVa
	@id 10405
	@name Longest Common Subsequence

	@tag Longest Common Subsequence
'''
from sys import stdin

def solve(xs, ys):
	n, m = len(xs), len(ys)
	dp = [ [ 0 for _ in range(m + 1) ] for _ in range(2) ]
	for x in range(n):
		pre, nxt = x & 1, (x + 1) & 1
		for y in range(m):
			if xs[x] == ys[y]:
				dp[nxt][y + 1] = dp[pre][y] + 1
			else:
				dp[nxt][y + 1] = max(dp[nxt][y], dp[pre][y + 1])
	return dp[n & 1][m]

for a, b in zip(*[ iter(stdin) ] * 2):
	print(solve(a.strip(), b.strip()))