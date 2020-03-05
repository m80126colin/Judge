'''
	CodeForces 1003A
	Polycarp's Pockets

	Tags: Counting
'''
from collections import Counter

input()
ans = max(Counter(input().split()).values())
print(ans)