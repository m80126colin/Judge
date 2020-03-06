'''
	@judge CodeForces
	@id 1167A
	@name Telephone Number

	@tag Ad-hoc
'''
def testCase():
	input()
	s = input()
	return s.find('8') >= 0 and len(s) - s.find('8') >= 11

t = int(input())
ans = map(lambda x: 'YES' if testCase() else 'NO', range(t))

print('\n'.join(ans))