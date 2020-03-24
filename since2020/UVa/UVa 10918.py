'''
	@judge UVa
	@id 10918
	@name Tri Tiling

	@tag Linear Dynamic Programming
'''
from sys import stdin

N = 15
dp = [ 1, 3 ]
for _ in range(2, N + 1):
	dp.append((dp[-1] << 2) - dp[-2])

def solve(n):
	if n % 2:
		return 0
	return dp[n >> 1]

for line in stdin:
	n = int(line)
	if n < 0:
		break
	print(solve(n))