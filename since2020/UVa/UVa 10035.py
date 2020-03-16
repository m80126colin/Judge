'''
	@judge UVa
	@id 10035
	@name Primary Arithmetic

	@tag Ad-hoc, Binary Operations
'''
from sys import stdin

def carrying(a, b):
	ans = 0
	c = 0
	while a != 0 or b != 0:
		c = 1 if a % 10 + b % 10 + c >= 10 else 0
		ans += c
		a //= 10
		b //= 10
	return ans
	
def solve():
	for line in stdin:
		a, b = map(int, line.split())
		if a == 0 and b == 0:
			return
		n = carrying(a, b)
		if n == 0:
			yield 'No carry operation.'
		elif n == 1:
			yield '1 carry operation.'
		else:
			yield f'{n} carry operations.'

print('\n'.join(solve()))