'''
	@judge CodeForces
	@id 1326A
	@name Bad Ugly Numbers
	
	@tag String Manipulation
'''
from sys import stdin

def solve(n):
	return '2' + '3' * (n - 1) if n > 1 else '-1'

input()
for line in stdin:
	print(solve(int(line)))