'''
	@judge CodeForces
	@id 1312A
	@name Two Regular Polygons

	@tag Geometry
'''
from sys import stdin

input()
for _, arr in zip(*[ iter(stdin) ] * 2):
	print(' '.join(sorted(arr.split(), key=lambda x: -int(x))))