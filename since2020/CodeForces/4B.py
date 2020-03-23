'''
	@judge CodeForces
	@id 4B
	@name Before an Exam

	@tag Math, Knapsack
'''
from sys import stdin

d, s  = tuple(map(int, input().split()))
times = [ tuple(map(int, line.split())) for line in stdin.readlines() ]

dp = [ [ (0, -1) for j in range(d + 1) ] for i in range(s + 1) ]

dp[0][0] = (1, -1)

for j in range(d):
	mn, mx = times[j]
	for i in range(s + 1):
		ox, _ = dp[i][j]
		if ox:
			for k in range(mn, min(mx + 1, s + 1 - i)):
				dp[i + k][j + 1] = (1, k)

flag = dp[s][d][0] == 1

print('YES' if flag else 'NO')
if flag:
	ans  = list()
	last = s
	for j in range(d, 0, -1):
		k = dp[last][j][1]
		ans = [ k ] + ans
		last = last - k
	print(*ans)