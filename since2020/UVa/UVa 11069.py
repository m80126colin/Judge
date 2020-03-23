'''
	@judge UVa
	@id 11069
	@name A Graph Problem

	@tag Linear Dynamic Programming
'''
from sys import stdin
from itertools import accumulate

N  = 77
dp = [ 1, 1, 2 ]
for x in range(3, N):
	dp.append(dp[-2] + dp[-3])

for line in stdin:
	print(dp[int(line)])