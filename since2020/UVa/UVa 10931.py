'''
	@judge UVa
	@id 10931
	@name Parity

	@tag Number Base Conversion, Parity
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

def solve(n):
	s = intToBase(n, 2)
	return 'The parity of {} is {} (mod 2).'.format(s, s.count('1'))

print('\n'.join([ solve(int(line)) for line in stdin if line.strip() != '0' ]))