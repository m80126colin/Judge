'''
	@judge CodeForces
	@id 758A
	@name Holiday Of Equality

	@tag Math
'''
n = int(input())
citizen = list(map(int, input().split()))

mx  = max(citizen)
ans = sum(map(lambda x: mx - x, citizen))

print(ans)