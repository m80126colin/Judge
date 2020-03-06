'''
	CodeForces 1320A
	Journey Planning

	Tags: Math, Grouping
'''
from itertools import groupby

def keyfunc(key):
	return key[0] - key[1]

input()
arr = list(map(int, input().split()))

ans = max(map(lambda g: sum(list(zip(*g[1]))[1]), groupby(sorted(enumerate(arr), key=keyfunc), keyfunc)))
print(ans)