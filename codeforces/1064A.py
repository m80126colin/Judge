'''
	CodeForces 1064A
	Make a triangle!

	Tags: Math
'''
arr = list(map(int, input().split()))
ans = 2 * max(arr) - sum(arr) + 1

print(ans if ans > 0 else 0)