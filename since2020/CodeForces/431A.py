'''
	@judge CodeForces
	@id 431A
	@name Black Square

	@tag Simulation
'''
cals = list(map(int, input().split()))
ans  = sum(map(lambda idx: cals[int(idx) - 1], input()))

print(ans)