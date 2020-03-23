'''
	@judge UVa
	@id 531
	@name Compromise

	@tag Longest Common Subsequence
'''
from sys import stdin

def solve(xs, ys):
	n, m = len(xs), len(ys)
	dp = [ [ list() for _ in range(m + 1) ] for _ in range(2) ]
	for x in range(n):
		pre, nxt = x & 1, (x + 1) & 1
		for y in range(m):
			if xs[x] == ys[y]:
				dp[nxt][y + 1] = dp[pre][y] + [ xs[x] ]
			else:
				dp[nxt][y + 1] = dp[nxt][y] if len(dp[nxt][y]) > len(dp[pre][y + 1]) else dp[pre][y + 1]
	return dp[n & 1][m]

test = list()
res  = list()

for line in stdin:
	if line.strip() == '#':
		test.append(res)
		res = list()
	else:
		res = res + line.split()

for a, b in zip(*[ iter(test) ] * 2):
	print(*solve(a, b))