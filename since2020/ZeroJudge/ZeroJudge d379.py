'''
	@judge ZeroJudge
	@id d379
	@name Kibbles `n' Bits `n' Bits `n' Bits
	@source UVa 446

	@tag Number Base Conversion, String Formatting
'''
from sys import stdin

def solve(line):
	arr = line.split()
	a = int(arr[0], 16)
	b = int(arr[-1], 16)
	c = a + b if arr[1] is '+' else a - b
	return f'{a:0>13b} {arr[1]} {b:0>13b} = {c}'

input()
print('\n'.join([ solve(line) for line in stdin ]))