'''
	CodeForces 758A
	Holiday Of Equality

	Tags: Math
'''
n = int(input())
citizen = list(map(int, input().split()))

mx  = max(citizen)
ans = sum(map(lambda x: mx - x, citizen))

print(ans)