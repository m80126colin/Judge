'''
	CodeForces 431A
	Black Square

	Tags: Simulation
'''
cals = list(map(int, input().split()))
ans  = sum(map(lambda idx: cals[int(idx) - 1], input()))

print(ans)