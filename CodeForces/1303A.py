'''
	CodeForce 1303A
	Erasing Zeroes
	
	Tags: String Manipulation
'''
from sys import stdin

input()
res = [ str(line.strip('\n').strip('0').count('0')) for line in stdin ]

print('\n'.join(res))