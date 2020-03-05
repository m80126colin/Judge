'''
	CodeForces 749A
	Bachgold Problem

	Tags: Math
'''
n   = int(input())
ans = [ 2 for x in range((n - 2) // 2) ] + [ 3 if n % 2 != 0 else 2 ]

print(n // 2)
print(*ans)