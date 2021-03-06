'''
	@judge CodeForces
	@id 1095A
	@name Repeating Cipher

	@tag String Manipulation
'''
from functools import reduce

n = int(input())
s = input()

def solve(p, curr):
	pos = p[1] + curr
	if pos >= n:
		return p
	return (p[0] + s[pos], pos)

ans, _ = reduce(solve, range(11), ('', 0))

print(ans)