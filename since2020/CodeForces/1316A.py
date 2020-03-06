'''
	@judge CodeForces
	@id 1316A
	@name Grade Allocation
	@contest CodeCraft-20 (Div. 2)

	@tag Simple Math, Ad-hoc
'''
t = int(input())

for _ in range(t):
	n, m = map(int, input().split())
	tot = sum(map(int, input().split()))

	print(min(tot, m))