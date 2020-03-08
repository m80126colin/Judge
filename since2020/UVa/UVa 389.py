'''
	@judge UVa
	@id 389
	@name Basically Speaking

	@tag Number Base Conversion, String Formatting
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

def solve(s, b1, b2):
	t = intToBase(int(s, int(b1)), int(b2))
	return '{:>7}'.format(t if len(t) <= 7 else 'ERROR')

print('\n'.join([ solve(*line.split()) for line in stdin ]))