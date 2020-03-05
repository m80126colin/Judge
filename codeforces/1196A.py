'''
	CodeForces 1196A
	Three Piles of Candies

	Tags: Game Theory
'''
from sys import stdin

q = int(input())
ans = [ str(sum(map(int, line.split())) // 2) for line in stdin.readlines() ]

print('\n'.join(ans))