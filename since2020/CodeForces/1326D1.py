'''
	@judge CodeForces
	@id 1326D1
	@name Prefix-Suffix Palindrome (Easy version)
	
	@tag Palindrome
'''
from sys import stdin
from itertools import takewhile

def isp(s):
	return all(map(lambda x: s[x] == s[~x], range(len(s) // 2)))

def greedy(s):
	if isp(s):
		return s
	for x in range(1, len(s)):
		if isp(s[:-x]):
			return s[:-x]
		if isp(s[x:]):
			return s[x:]
	return ''

def solve(s):
	ps = list(takewhile(lambda p: p[0] == p[1], map(lambda x: (s[x], s[~x]), range(len(s) // 2))))
	k = len(ps)
	if k > 0:
		prefix, _ = zip(*ps)
		return ''.join(prefix) + greedy(s[k:-k]) + ''.join(prefix[::-1])
	return greedy(s)

input()
for line in stdin:
	print(solve(line.strip()))