'''
	@judge CodeForces
	@id 200B
	@name Drinks

	@tag Math
'''
n   = int(input())
ans = sum(map(int, input().split())) / n

print(ans)