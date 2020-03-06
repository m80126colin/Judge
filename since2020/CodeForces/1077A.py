'''
	@judge CodeForces
	@id 1077A
	@name Frog Jumping

	@tag Math
'''
t = int(input())

for x in range(t):
	a, b, k = tuple(map(int, input().split()))
	print((a - b) * (k // 2) + a * (k % 2))