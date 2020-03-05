'''
	CodeForces 1A
	Theatre Square

	Tags: Math
'''
from math import ceil

n, m, a = tuple(map(int, input().split()))
print(ceil(n / a) * ceil(m / a))