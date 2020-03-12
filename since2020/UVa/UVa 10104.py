'''
	@judge UVa
	@id 10104
	@name Euclid Problem

	@tag Extended Euclidean Algorithm
'''
from sys import stdin

def ExtGCD(a, b):
	if a % b == 0:
		return (b, 0, 1)
	g, x, y = ExtGCD(b, a % b)
	return (g, y, x - (a // b) * y)

for line in stdin:
	a, b = map(int, line.split())
	g, x, y = ExtGCD(a, b)
	print(x, y, g)