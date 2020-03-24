'''
	@judge UVa
	@id 11456
	@name Trainsorting

	@tag Longest Increasing Subsequence, Monotonicity
'''
from sys import stdin
from bisect import bisect_left

def solve(arr, n):
	if n == 0:
		return 0
	ls = arr[::-1] + arr
	lis = []
	for x in ls:
		if not lis or lis[-1] < x:
			lis.append(x)
		else:
			lis[ bisect_left(lis, x) ] = x
	return len(lis)

t = int(input())
while t > 0:
	n = int(input())
	arr = [ int(input()) for _ in range(n) ]
	print(solve(arr, n))
	t -= 1