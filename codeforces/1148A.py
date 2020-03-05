'''
	CodeForces 1148A
	Another One Bites The Dust

	Tags: Ad-hoc
'''
a, b, c = map(int, input().split())
ans = min(a, b) + c
print(ans * 2 + int(max(a, b) != min(a, b)))