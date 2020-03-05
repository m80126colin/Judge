'''
	CodeForces 1077A
	Frog Jumping

	Tags: Math
'''
t = int(input())

for x in range(t):
	a, b, k = tuple(map(int, input().split()))
	print((a - b) * (k // 2) + a * (k % 2))