'''
	@judge UVa
	@id 10071
	@name Back to High School Physics

	@tag Binary Operations
'''
from sys import stdin

def solve(line):
	t, v = map(int, line.split())
	return 2 * t * v

ans = [ str(solve(line)) for line in stdin ]

print('\n'.join(ans))