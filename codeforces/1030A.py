'''
	CodeForces 1030A
	In Search of an Easy Problem

	Tags: Ad-hoc
'''
import re

input()
s = input()

print('HARD' if re.search('1', s) is not None else 'EASY')