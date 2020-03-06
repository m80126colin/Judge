'''
	CodeForces 1305B, Ozon Tech Challenge 2020
	Kuroni and Simple Strings

	Tags: String Manipulation, Greedy
'''
from itertools import accumulate

def solve(p, L, R):
	if p[1] is '(' and L <= R:
		return True
	if p[1] is ')' and L >= R:
		return True
	return False

s = input()

left  = list(accumulate([ 1 if ch is '(' else 0 for ch in s ]))
right = list(reversed(list(accumulate([ 1 if ch is ')' else 0 for ch in reversed(s) ]))))

ans = list(map(lambda x: str(x[0] + 1), filter(lambda p: solve(p, left[p[0]], right[p[0]]), enumerate(s))))

if len(ans) == 0:
	print('0')
else:
	print('1')
	print(len(ans))
	print(' '.join(ans))