'''
	CodeForces 935A
	Fafa and his Company

	Tags: Math, Prime
'''
from math import sqrt

n = int(input())
m = int(sqrt(n))
ans = len(list(filter(lambda x: n % x == 0, range(2, m + 1)))) * 2 + 1 - (1 if m * m == n else 0)

print(ans)