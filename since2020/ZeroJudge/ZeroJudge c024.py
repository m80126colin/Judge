'''
	@judge ZeroJudge
	@id c024
	@name Pizza Cutting
	@source UVa 10079

	@tag Triangular Number
'''
from sys import stdin

def solve(n):
	return n * (n + 1) // 2 + 1

for line in stdin:
	n = int(line)
	if n < 0:
		break
	print(solve(n))