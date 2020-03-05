'''
	CodeForces 1143A
	The Doors

	Tags: Ad-hoc
'''
input()
s   = input()
pos = min(s.rfind('1'), s.rfind('0'))

print(pos // 2 + 1)