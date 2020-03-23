'''
	@judge UVa
	@id 111
	@name History Grading

	@tag Longest Increasing Subsequence, Sortings
'''
from sys import stdin

def solve(arr):
	n  = len(arr)
	dp = [ 1 ]
	for x in range(1, n):
		dp.append(max([ 1 ] + [ dp[y] + 1 for y in range(x) if arr[y] < arr[x] ]))
	return max(dp)

input()
d = dict(map(lambda p: (p[0], p[1]), enumerate(map(int, input().split()))))

for line in stdin:
	arr = list(map(lambda p: d[p[0]], sorted(enumerate(map(int, line.split())), key=lambda p: p[1])))
	print(solve(arr))