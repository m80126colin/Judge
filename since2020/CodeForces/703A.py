'''
	CodeForces 703A
	Mishka and Game

	Tags: Counting, Ad-hoc
'''
def tripleCond(L, R, s1 = '', s2 = '', s3 = ''):
	if L > R:
		return s1
	if L < R:
		return s2
	return s3

def judge(p):
	if p[0] > p[1]:
		return 'M'
	if p[1] < p[0]:
		return 'C'
	return ''

n = int(input())

row = ''.join([ tripleCond(*input().split(), 'M', 'C') for x in range(n) ])
ans = tripleCond(row.count('M'), row.count('C'), 'Mishka', 'Chris', 'Friendship is magic!^^')

print(ans)