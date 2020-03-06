'''
	@judge CodeForces
	@id 581A
	@name Vasya the Hipster

	@tag Math
'''
tup = tuple(map(int, input().split()))
mn, mx = min(tup), max(tup)

print(mn, (mx - mn) // 2)