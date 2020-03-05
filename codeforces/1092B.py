'''
	CodeForces 1092B
	Teams Forming

	Tags: Sorting
'''
n   = int(input())
arr = sorted(map(int, input().split()), key=lambda x: -x)
ans = sum(map(lambda idx: arr[idx] - arr[idx + 1], range(0, n, 2)))

print(ans)