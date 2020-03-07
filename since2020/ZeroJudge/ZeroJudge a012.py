'''
	@judge ZeroJudge
	@id a012
	@name Hashmat the Brave Warrior
	@source UVa 10055

	@tag Arithematic Operation
'''
from sys import stdin

res = [ str((lambda a, b: abs(a - b))(*map(int, line.split()))) for line in stdin ]
print('\n'.join(res))