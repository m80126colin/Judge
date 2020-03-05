'''
	CodeForces 581A
	Vasya the Hipster

	Tags: Math
'''
tup = tuple(map(int, input().split()))
mn, mx = min(tup), max(tup)

print(mn, (mx - mn) // 2)