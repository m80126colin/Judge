'''
	@judge CodeForces
	@id 1270A
	@name Card Game

	@tag Game Theory, Ad-hoc
'''
def testCase():
	input()
	p1 = max(map(int, input().split()))
	p2 = max(map(int, input().split()))
	return 'YES' if p1 > p2 else 'NO'

t = int(input())
ans = map(lambda x: testCase(), range(t))

print('\n'.join(ans))