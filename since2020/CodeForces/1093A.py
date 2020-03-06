'''
	@judge CodeForces
	@id 1093A
	@name Dice Rolling

	@tag Math
'''
from math import ceil

t = int(input())
ans = list(map(lambda x: str(ceil(int(input()) / 7)), range(t)))

print('\n'.join(ans))