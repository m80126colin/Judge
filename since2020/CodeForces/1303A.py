'''
	@judge CodeForces
	@id 1303A
	@name Erasing Zeroes
	
	@tag String Manipulation
'''
from sys import stdin

input()
res = [ str(line.strip('\n').strip('0').count('0')) for line in stdin ]

print('\n'.join(res))