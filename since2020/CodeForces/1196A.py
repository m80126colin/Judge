'''
	@judge CodeForces
	@id 1196A
	@name Three Piles of Candies

	@tag Game Theory
'''
from sys import stdin

q = int(input())
ans = [ str(sum(map(int, line.split())) // 2) for line in stdin.readlines() ]

print('\n'.join(ans))