'''
	@judge ZeroJudge
	@id d242
	@name What Goes Up

	@tag Longest Increasing Subsequence
'''
from sys import stdin
from bisect import bisect_left

arr = [ int(line) for line in stdin ]

lis = []
dp  = []
for x in arr:
	if not lis or lis[-1] < x:
		dp.append(len(lis))
		lis.append(x)
	else:
		pos = bisect_left(lis, x)
		dp.append(pos)
		lis[pos] = x

ans = len(lis)
ls  = []
for x in range(len(arr) - 1, -1, -1):
	if dp[x] == ans - len(ls) - 1:
		ls.append(arr[x])

print('{}\n-'.format(len(lis)))
print('\n'.join(map(str, reversed(ls))))