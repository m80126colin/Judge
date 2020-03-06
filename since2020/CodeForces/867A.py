'''
	@judge CodeForces
	@id 867A
	@name Between the Offices

	@tag String Manipulation
'''
input()
s = input()

ans = s.count('SF') - s.count('FS')
print('YES' if ans > 0 else 'NO')