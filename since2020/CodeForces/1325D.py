'''
	@judge CodeForces
	@id 1325D
	@name Ehab the Xorcist
	@contest Codeforces Round #628

	@tag Math, Greedy, Binary Operations
'''
from sys import stdin

for line in stdin:
	u, v = map(int, line.split())
	if u > v or (v - u) % 2 == 1:
		print('-1')
	elif u == v:
		if v == 0:
			print('0')
		else:
			print('1')
			print(u)
	else:
		t = (v - u) // 2
		if (u & t) == 0:
			print('2')
			print(f'{u + t} {t}')
		else:
			print('3')
			print(f'{u} {t} {t}')