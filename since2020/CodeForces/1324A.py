'''
	@judge CodeForces
	@id 1324A
	@name Yet Another Tetris Problem
	@contest Codeforces Round #627
	
	@tag Ad-hoc, Basic Operations
'''
from sys import stdin

input()
for _, line in zip(*[ iter(stdin) ] * 2):
	arr = list(map(int, line.split()))
	M = max(arr)
	flag = all(map(lambda x: (M - x) % 2 == 0, arr))
	print('YES' if flag else 'NO')