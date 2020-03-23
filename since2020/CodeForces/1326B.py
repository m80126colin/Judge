'''
	@judge CodeForces
	@id 1326B
	@name Maximums
	
	@tag Simple Math, Simulation
'''
def solve(arr):
	M = 0
	for x in arr:
		yield x + M
		if x > 0:
			M += x

input()
print(*solve(list(map(int, input().split()))))