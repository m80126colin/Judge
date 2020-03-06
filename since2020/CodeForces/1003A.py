'''
	@judge CodeForces
	@id 1003A
	@name Polycarp's Pockets

	@tag Counting
'''
from collections import Counter

input()
ans = max(Counter(input().split()).values())
print(ans)