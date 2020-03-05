'''
	CodeForces 1244A
	Pens and Pencils

	Tags: Math
'''
from math import ceil

def testCase():
	a, b, c, d, k = tuple(map(int, input().split()))
	x = ceil(a / c)
	y = ceil(b / d)
	if x + y > k:
		return '-1'
	return '{} {}'.format(x, k - x)

t = int(input())
ans = map(lambda x: testCase(), range(t))

print('\n'.join(ans))