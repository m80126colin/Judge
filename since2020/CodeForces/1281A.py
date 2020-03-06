'''
	CodeForces 1281A
	Suffix Three

	Tags: String manipulation
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