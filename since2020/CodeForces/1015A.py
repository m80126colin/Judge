'''
	@judge CodeForces
	@id 1015A
	@name Points in Segments

	@tag Simulation
'''
from sys import stdin
from functools import reduce

n, m = tuple(map(int, input().split()))
segments = [ tuple(map(int, line.split())) for line in stdin.readlines() ]

ans = list(reduce(lambda nums, p: filter(lambda x: x < p[0] or p[1] < x, nums), segments, range(1, m + 1)))

print(len(ans))
print(*ans)