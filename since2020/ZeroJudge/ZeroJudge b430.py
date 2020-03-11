'''
	@judge ZeroJudge
	@id b430
	@name 簡單乘法

	@tag Modulus
'''
from sys import stdin

print('\n'.join([ (lambda a, b, n: str(a * b % n))(*map(int, line.split())) for line in stdin ]))