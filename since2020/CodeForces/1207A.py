'''
	@judge CodeForces
	@id 1207A
	@name There Are Two Types Of Burgers

	@tag Math, Greedy, Knapsack
'''
def testCase():
	bun, p, f = tuple(map(int, input().split()))
	h, c = tuple(map(int, input().split()))
	count = bun // 2
	if h < c:
		f, p = p, f
		c, h = h, c
	n1 = min(count, p)
	n2 = min(count - n1, f)
	return n1 * h + n2 * c

t = int(input())
ans = [ str(testCase()) for x in range(t) ]

print('\n'.join(ans))