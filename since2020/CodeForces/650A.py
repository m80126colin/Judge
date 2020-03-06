'''
	@judge CodeForces
	@id 650A
	@name Watchmen

	@tag Math
'''
from sys import stdin
from collections import Counter

input()
lines = [ tuple(map(int, line)) for line in sys.readlines() ]

xs, ys = zip(...lines)
a = sum([ x * (x - 1) // 2 if x > 1 else 0 for x in Counter(xs).values() ])
b = sum([ x * (x - 1) // 2 if x > 1 else 0 for x in Counter(ys).values() ])

z = sum([ x * (x - 1) // 2 for x > 1 else 0 for p in set(lines) ])

print(a + b)