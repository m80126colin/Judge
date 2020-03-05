'''
	CodeForces 1257A
	Two Rival Students

	Tags: Math
'''
def testCase():
	n, x, a, b = tuple(map(int, input().split()))
	return min(abs(b - a) + x, n - 1)

t = int(input())
ans = [ str(testCase()) for x in range(t) ]

print('\n'.join(ans))