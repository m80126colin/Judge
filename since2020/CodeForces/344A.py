'''
	@judge CodeForces
	@id 344A
	@name Magnets

	@tag Ad-hoc, String Manipulation
'''
from sys import stdin
 
n = int(input())
 
magnet = ''.join(map(lambda x: x[0], stdin.readlines()))
ans    = magnet.count('01') + magnet.count('10') + 1
 
print(ans)