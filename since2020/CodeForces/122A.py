'''
	@judge CodeForces
	@id 122A
	@name Lucky Division

	@tag Math
'''

'''
def luckyNumber(x):
	s = str(x)
	return len(s) == s.count('4') + s.count('7')

mx = 1000
lucky = list(filter(luckyNumber, range(1, mx + 1)))
'''

lucky = [4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777]
n = int(input())

print('YES' if any(map(lambda x: n % x == 0, lucky)) else 'NO')