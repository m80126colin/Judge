from sys import stdin
import re

BASE = 26

def toNum(s):
	res = 0
	for ch in s:
		res *= BASE
		res += ord(ch) - ord('A') + 1
	return res

def fromNum(n):
	res = ''
	while n > 0:
		res = chr((n - 1) % BASE + ord('A')) + res
		n = (n - 1) // BASE
	return res

def solve(s):
	A, B, C = re.search(r'^(\D+)(\d+)(?:\D(\d+))?$', s).groups()
	if C is None:
		return f'R{B}C{toNum(A)}'
	return f'{fromNum(int(C))}{B}'

input()
res = [ solve(line.strip()) for line in stdin ]
print('\n'.join(res))