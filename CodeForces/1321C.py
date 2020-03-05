'''
	CodeForces 1321C
	Remove Adjacent

	Tags: Ad-hoc, String Manipulation
'''
import re
from functools import reduce

def iter(s, idx):
	chA  = chr(ord('a') + idx - 1)
	chB  = chr(ord(chA) + 1)
	patL = re.compile(f'{chA}{chB}+')
	patR = re.compile(f'{chB}+{chA}')
	return re.sub(patR, chA, re.sub(patL, chA, s))

origin = int(input())
s = reduce(iter, range(25, 0, -1), input().strip())

print(origin - len(s))