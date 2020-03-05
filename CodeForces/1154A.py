'''
	CodeForces 1154A
	Restoring Three Numbers

	Tags: Math
'''
ls  = list(map(int, input().split()))
m   = max(ls)
res = filter(lambda x: x > 0, map(lambda y: m - y, ls))

print(*res)