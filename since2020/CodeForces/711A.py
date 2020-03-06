'''
	CodeForces 711A
	Bus to Udayland

	Tags: Simpulation, String manipulation
'''
from sys import stdin

input()
seats = ''.join(stdin.readlines())
flag  = seats.find('OO') >= 0

print('YES' if flag else 'NO')
if flag:
	print(seats.replace('OO', '++', 1))