'''
	@judge CodeForces
	@id 1154A
	@name Restoring Three Numbers

	@tag Math
'''
ls  = list(map(int, input().split()))
m   = max(ls)
res = filter(lambda x: x > 0, map(lambda y: m - y, ls))

print(*res)