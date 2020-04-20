'''
	@judge CodeForces
	@id 1328C
	@name Ternary XOR
	@contest Codeforces Round #629 (Div. 3)

	@tag Greedy, Binary Operations
'''
from sys import stdin

def solve(n, x):
	flag = False
	a, b = [], []
	for ch in x:
		if flag == True:
			a.append('0')
			b.append(ch)
		elif (ord(ch) - ord('0')) % 2 == 1:
			a.append('1')
			b.append('0')
			flag = True
		else:
			k = chr((ord(ch) - ord('0')) // 2 + ord('0'))
			a.append(k)
			b.append(k)
	print('{}\n{}'.format(''.join(a), ''.join(b)))

input()
for a, b in zip(*[ iter(stdin) ] * 2):
	n = int(a)
	x = b.strip()
	solve(n, x)