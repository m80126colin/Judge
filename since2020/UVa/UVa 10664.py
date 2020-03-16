'''
	@judge UVa
	@id 10664
	@name Luggage

	@tag Subset Sum
'''
from sys import stdin

def solve(arr):
	N = sum(arr)
	if N & 1:
		return False
	N = N // 2
	dp = [ False ] * (N + 1)
	dp[0] = True
	for x in arr:
		if dp[-1]:
			return True
		for pos in range(N - x, -1, -1):
			dp[pos + x] = dp[pos + x] or dp[pos]
	return dp[-1]

n = int(input())
for _ in range(n):
	print('YES' if solve(list(map(int, stdin.readline().split()))) else 'NO')