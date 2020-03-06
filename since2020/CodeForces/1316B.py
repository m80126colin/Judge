'''
	@judge CodeForces
	@id 1316B
	@name String Modification
	@contest CodeCraft-20 (Div. 2)

	@tag String Manipulation
'''
from functools import reduce

def flip(s, k):
	return s[k:] + s[:k][::-1 if len(s) % 2 != k % 2 else 1]

def cmp(pL, pR):
	return pR if pR[1] < pL[1] else pL

for _ in range(int(input())):
	n = int(input())
	s = input()

	ans = reduce(cmp, map(lambda k: (k + 1, flip(s, k)), range(n)))
	print(ans[1])
	print(ans[0])