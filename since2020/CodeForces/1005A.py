'''
	@judge CodeForces
	@id 1005A
	@name Tanya and Stairways

	@tag Ad-hoc
'''
n = int(input())
arr = list(map(int, input().split()))
ans = map(lambda p: p[0], filter(lambda p: p[1] == 1, zip(arr, arr[1:])))

print(arr.count(1))
print(*ans, arr[-1])