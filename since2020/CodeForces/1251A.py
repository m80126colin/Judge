'''
	@judge CodeForces
	@id 1251A
	@name Broken Keyboard

	@tag Simulation
'''
from sys import stdin
from itertools import groupby

def solve(s):
	return ''.join(sorted(set(map(lambda p: str(p[0]), filter(lambda p: len(list(p[1])) & 1, groupby(s))))))

input()
for line in stdin:
	print(solve(line.strip()))