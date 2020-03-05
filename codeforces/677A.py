'''
	CodeForces 677A
	Vanya and Fence

	Tags: Math
'''
n, h = tuple(map(int, input().split()))
ans  = sum(map(lambda x: 1 if int(x) <= h else 2, input().split()))

print(ans)