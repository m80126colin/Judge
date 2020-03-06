'''
	@judge CodeForces
	@id 1281A
	@name Suffix Three

	@tag String Manipulation
'''
def solve(s):
	if s[-2:] == 'po':
		return 'FILIPINO'
	if s[-4:] == 'desu' or s[-4:] == 'masu':
		return 'JAPANESE'
	return 'KOREAN'

t = int(input())
ans = [ solve(input()) for x in range(t) ]

print('\n'.join(ans))