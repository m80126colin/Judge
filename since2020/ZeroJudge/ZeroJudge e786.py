'''
	@judge ZeroJudge
	@id e786
	@name b1.修辭迴文(Palindrome)

	@tag Palindrome, Distinct Item
'''
from sys import stdin

def solve(s):
	h = len(s) // 2
	if (len(s) & 1) or s[:h] != s[h:][::-1]:
		print('NO')
		return
	print('YES')
	print(s[:h])
	return

for line in stdin:
	solve(line.strip())