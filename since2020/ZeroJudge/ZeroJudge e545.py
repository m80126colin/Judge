'''
	@judge ZeroJudge
	@id e545
	@name Funny Encryption Method
	@source UVa 10019

	@tag Number Base Conversion, Parity
'''
from sys import stdin
from functools import reduce

def parityGen(n):
	while n > 0:
		yield n & 1
		n >>= 1
	return

def parity(n):
	return reduce(lambda p, c: p + c, parityGen(n))

def solve(line):
	return '{} {}'.format(parity(int(line, 10)), parity(int(line, 16)))

input()
print('\n'.join([ solve(line) for line in stdin ]))