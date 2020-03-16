'''
	@judge ZeroJudge
	@id d390
	@name Dividing coins
	@source UVa 562

	@tag Subset Sum, Bitmasking
'''
from sys import stdin

def solve(arr):
	N  = sum(arr) // 2
	dp = 1
	for x in arr:
		dp |= dp << x
	M = max([ x for x in range(N + 1) if dp & (1 << x) ])
	return sum(arr) - (M << 1)

input()
for _, line in zip(*[ iter(stdin) ] * 2):
	print(solve(list(map(int, line.split()))))