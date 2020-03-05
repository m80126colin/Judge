'''
	CodeForces 987A
	Infinity Gauntlet

	Tags: Ad-hoc
'''
from sys import stdin

table = {
	'purple': 'Power',
	'green': 'Time',
	'blue': 'Space',
	'orange': 'Soul',
	'red': 'Reality',
	'yellow': 'Mind'
}
input()
ans = set(table.values()) - set(map(lambda x: table[x.strip()], stdin))
print(len(ans))
print('\n'.join(list(ans)))