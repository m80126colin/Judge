'''
	CodeForces 136A
	Presents

	Tags: Sort
'''
n   = int(input())
ans = sorted(list(zip(input().split(), range(1, n + 1))), key=lambda p: int(p[0]))

print(*map(lambda p: p[1], ans))