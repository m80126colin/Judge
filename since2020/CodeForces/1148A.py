'''
	@judge CodeForces
	@id 1148A
	@name Another One Bites The Dust

	@tag Ad-hoc
'''
a, b, c = map(int, input().split())
ans = min(a, b) + c
print(ans * 2 + int(max(a, b) != min(a, b)))