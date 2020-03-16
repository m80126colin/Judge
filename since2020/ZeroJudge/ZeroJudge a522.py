'''
	@judge ZeroJudge
	@id a522
	@name Bars
	@source UVa 12455

	@tag Subset Sum
'''
from sys import stdin

def solve(n, stick):
	dp = [ False ] * (n + 1)
	dp[0] = True
	for s in stick:
		if dp[n]:
			return True
		for x in range(n - s, -1, -1):
			dp[x + s] = dp[x] or dp[x + s]
	return dp[n]

input()
for n, _, stick in zip(*[ iter(stdin) ] * 3):
	print('YES' if solve(int(n), list(map(int, stick.split()))) else 'NO')