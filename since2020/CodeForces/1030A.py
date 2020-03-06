'''
	@judge CodeForces
	@id 1030A
	@name In Search of an Easy Problem

	@tag Ad-hoc
'''
import re

input()
s = input()

print('HARD' if re.search('1', s) is not None else 'EASY')