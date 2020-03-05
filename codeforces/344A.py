'''
	CodeForces 344A
	Magnets

	Tags: Ad-hoc, String manipulation
'''
from sys import stdin
 
n = int(input())
 
magnet = ''.join(map(lambda x: x[0], stdin.readlines()))
ans    = magnet.count('01') + magnet.count('10') + 1
 
print(ans)