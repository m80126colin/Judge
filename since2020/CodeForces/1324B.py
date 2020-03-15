'''
	@judge CodeForces
	@id 1324B
	@name Yet Another Palindrome Problem
	@contest Codeforces Round #627
	
	@tag Palindrome
'''
from sys import stdin
from itertools import groupby

def solve(arr):
	return any(
		map(lambda p: max(p) - min(p) > 1,
			map(lambda ps: [ x for x, _ in ps[1] ],
				groupby(sorted(enumerate(arr), key=lambda p: p[1]), key=lambda p: p[1])
	)))

input()
for _, line in zip(*[ iter(stdin) ] * 2):
	arr = line.split()
	print('YES' if solve(arr) else 'NO')