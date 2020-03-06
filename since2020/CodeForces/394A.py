'''
	@judge CodeForces
	@id 394A
	@name Counting Sticks

	@tag String Manipulation
'''
import re

def stickToTuple(s):
	temp = re.match(r'(\|+)\+(\|+)=(\|+)', s)
	return tuple(map(len, temp.groups()))

def tupleToStick(a, b, c):
	return '{}+{}={}'.format('|' * a, '|' * b, '|' * c)

def solve(a, b, c):
	if a + b == c:
		return tupleToStick(a, b, c)
	if a + b - 1 == c + 1:
		if a > 1:
			return tupleToStick(a - 1, b, c + 1)
		return tupleToStick(a, b - 1, c + 1)
	if a + b + 1 == c - 1 and c > 1:
		return tupleToStick(a + 1, b, c - 1)
	return 'Impossible'

s = input()
print(solve(*stickToTuple(s)))