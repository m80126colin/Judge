'''
	@judge CodeForces
	@id 1285A
	@name Mezo Playing Zoma

	@tag Counting
'''
n = int(input())
s = input()
ans = s.count('L') + s.count('R') + 1

print(ans)