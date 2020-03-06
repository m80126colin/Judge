'''
	@judge CodeForces
	@id 734A
	@name Anton and Danik

	@tag Ad-hoc, Counting
'''
def solve(s):
	a = s.count('A') - s.count('D')
	if a > 0:
		return 'Anton'
	if a < 0:
		return 'Danik'
	return 'Friendship'

input()
s = input()

print(solve(s))