'''
	@judge UVa
	@id 580
	@name Critical Mass

	@tag Linear Dynamic Programming
'''
from sys import stdin

N  = 30
dp = [ 1, 2, 4 ]
for n in range(3, N + 1):
	dp.append(dp[-1] + dp[-2] + dp[-3])

ans = [ 2 ** n - dp[n] for n in range(N + 1) ]

for line in stdin:
	n = int(line)
	if n == 0:
		break
	print(ans[n])