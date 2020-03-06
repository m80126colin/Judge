'''
	@judge CodeForces
	@id 677A
	@name Vanya and Fence

	@tag Math
'''
n, h = tuple(map(int, input().split()))
ans  = sum(map(lambda x: 1 if int(x) <= h else 2, input().split()))

print(ans)