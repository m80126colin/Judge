'''
	@judge UVa
	@id 11310
	@name DELIVERY DEBACLE

	@tag Linear Dynamic Programming
'''
from sys import stdin

N  = 40
dp = [ 1, 1, 5 ]
for x in range(3, N + 1):
	dp.append(dp[-1] + 4 * dp[-2] + 2 * dp[-3])

input()
for line in stdin:
	print(dp[int(line)])