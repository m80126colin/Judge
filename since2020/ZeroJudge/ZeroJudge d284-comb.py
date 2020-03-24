'''
	@judge ZeroJudge
	@id d284
	@name Combinations

	@tag Combinatorics, Big Number
'''
from sys import stdin

def solve(n):
	return 2 ** (n - 1) * (4 ** n + 5 ** n)

for line in stdin:
	n = int(line)
	if n == 0:
		break
	print(solve(n))