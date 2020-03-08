'''
	@judge ZeroJudge
	@id d226
	@name Back to High School Physics
	@source UVa 10071

	@tag Arithematic Operation
'''
from sys import stdin

def solve(line):
	t, v = map(int, line.split())
	return 2 * t * v

ans = [ str(solve(line)) for line in stdin ]

print('\n'.join(ans))