'''
	@judge CodeForces
	@id 1312A
	@name Two Regular Polygons

	@tag Geometry
'''
from sys import stdin

input()
for line in stdin:
	n, m = map(int, line.split())
	print('YES' if n % m == 0 else 'NO')