'''
	CodeForces 4C
	Registration system

	Tags: Simulation
'''
from sys import stdin

n = int(input())
db = dict()
for line in map(lambda x: x.strip('\n'), stdin.readlines()):
	if line in db.keys():
		print('{}{}'.format(line, db[line]))
		db[line] += 1
	else:
		db[line] = 1
		print('OK')