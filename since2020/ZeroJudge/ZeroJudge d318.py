'''
	@judge ZeroJudge
	@id d318
	@name Ternary
	@source UVa 11185

	@tag Number Base Conversion
'''
from sys import stdin

def intToBaseGen(x, b):
	if x == 0:
		yield '0'
	while x != 0:
		i = x % b
		yield chr(ord('0') + i) if i < 10 else chr(ord('A') + i - 10)
		x //= b
	return

def intToBase(x, b):
	return ''.join(list(intToBaseGen(x, b))[::-1])

print('\n'.join([ intToBase(int(line), 3) for line in stdin if line.count('-') == 0 ]))