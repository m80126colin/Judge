'''
	CodeForces 1285A
	Mezo Playing Zoma

	Tags: Counting
'''
n = int(input())
s = input()
ans = s.count('L') + s.count('R') + 1

print(ans)