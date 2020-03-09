'''
	@judge ZeroJudge
	@id e786
	@name Pesky Palindromes
	@source UVa 353

	@tag Palindrome
'''
from itertools import combinations
from sys import stdin

def isPalindrome(s):
	return all(map(lambda p: p[0] == p[1], zip(s, s[::-1])))

def solve(s):
	ss = set(map(lambda p: s[p[0]:p[1]], combinations(range(len(s) + 1), 2)))
	res = len(list(filter(lambda s: isPalindrome(s), ss)))
	return f'The string \'{s}\' contains {res} palindromes.'

print('\n'.join([ solve(line.strip()) for line in stdin ]))