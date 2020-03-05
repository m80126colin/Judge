'''
	CodeForces 1093A
	Dice Rolling

	Tags: Math
'''
from math import ceil

t = int(input())
ans = list(map(lambda x: str(ceil(int(input()) / 7)), range(t)))

print('\n'.join(ans))