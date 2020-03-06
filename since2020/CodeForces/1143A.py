'''
	@judge CodeForces
	@id 1143A
	@name The Doors

	@tag Ad-hoc
'''
input()
s   = input()
pos = min(s.rfind('1'), s.rfind('0'))

print(pos // 2 + 1)