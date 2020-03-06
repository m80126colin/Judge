'''
	CodeForces 1220A
	Cards

	Tags: Counting
'''
from collections import Counter

input()
d = Counter(input())
digit = min(min(d['z'], d['r']) + d['n'], min(d['o'], d['e']))
one   = min(d['o'], d['n'], d['e'])
ans   = '1 ' * one + '0 ' * (digit - one)

print(ans)