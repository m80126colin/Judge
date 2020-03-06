'''
	@judge CodeForces
	@id 1244A
	@name Pens and Pencils

	@tag Math
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