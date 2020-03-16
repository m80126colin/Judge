'''
	@judge UVa
	@id 10055
	@name Hashmat the Brave Warrior

	@tag Binary Operations
'''
from sys import stdin

res = [ str((lambda a, b: abs(a - b))(*map(int, line.split()))) for line in stdin ]
print('\n'.join(res))