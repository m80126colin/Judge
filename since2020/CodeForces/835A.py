'''
	@judge CodeForces
	@id 835A
	@name Key races

	@tag Ad-hoc, Math
'''
def tripleCond(L, R, s1 = '', s2 = '', s3 = ''):
	if L < R:
		return s1
	if L > R:
		return s2
	return s3

s, v1, v2, t1, t2 = tuple(map(int, input().split()))
ans = tripleCond(s * v1 + t1 * 2, s * v2 + t2 * 2, 'First', 'Second', 'Friendship')

print(ans)