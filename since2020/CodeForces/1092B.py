'''
	@judge CodeForces
	@id 1092B
	@name Teams Forming

	@tag Sortings
'''
n   = int(input())
arr = sorted(map(int, input().split()), key=lambda x: -x)
ans = sum(map(lambda idx: arr[idx] - arr[idx + 1], range(0, n, 2)))

print(ans)