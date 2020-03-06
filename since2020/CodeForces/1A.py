'''
	@judge CodeForces
	@id 1A
	@name Theatre Square

	@tag Math
'''
from math import ceil

n, m, a = tuple(map(int, input().split()))
print(ceil(n / a) * ceil(m / a))