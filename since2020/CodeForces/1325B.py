'''
	@judge CodeForces
	@id 1325B
	@name CopyCopyCopyCopyCopy
	@contest Codeforces Round #628

	@tag Distinct Item
'''
from sys import stdin

input()
for _, line in zip(*[ iter(stdin) ] * 2):
	print(len(set(line.split())))