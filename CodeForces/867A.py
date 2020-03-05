'''
	CodeForces 867A
	Between the Offices

	Tags: String Manipulation
'''
input()
s = input()

ans = s.count('SF') - s.count('FS')
print('YES' if ans > 0 else 'NO')