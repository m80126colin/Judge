'''
	@judge CodeForces
	@id 1324D
	@name Pair of Topics
	@contest Codeforces Round #627
	
	@tag Sortings, Binary Search, Two Pointers
'''
from bisect import bisect_left

def solve(arr, n):
	ans = 0
	ls = sorted(arr)
	L, R = 0, n - 1
	while L < R:
		while L < R and ls[L] + ls[R] <= 0:
			L += 1
		ans += R - L
		R -= 1
	return ans

n = int(input())
arr = list(map(int, input().split()))
brr = list(map(int, input().split()))

print(solve(list([ arr[x] - brr[x] for x in range(n) ]), n))