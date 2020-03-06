'''
	@judge CodeForces
	@id 711A
	@name Bus to Udayland

	@tag Simpulation, String manipulation
'''
from sys import stdin

input()
seats = ''.join(stdin.readlines())
flag  = seats.find('OO') >= 0

print('YES' if flag else 'NO')
if flag:
	print(seats.replace('OO', '++', 1))