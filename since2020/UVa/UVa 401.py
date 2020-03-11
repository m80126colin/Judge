'''
	@judge UVa
	@id 401
	@name Palindromes

	@tag Palindrome, String Manipulation
'''
from sys import stdin

table = dict(zip('AEHIJLMOSTUVWXYZ012358', 'A3HILJMO2TUVWXY501SEZ8'))

def isPalindrome(s):
	return s == s[::-1]

def isMirror(s):
	return all(map(lambda p: p[1] in table and p[0] == table[p[1]], zip(s,s[::-1])))

def solve(s):
	mirror = isMirror(s)
	palin  = isPalindrome(s)
	if mirror and palin:
		return f'{s} -- is a mirrored palindrome.\n'
	if mirror:
		return f'{s} -- is a mirrored string.\n'
	if palin:
		return f'{s} -- is a regular palindrome.\n'
	return f'{s} -- is not a palindrome.\n'

print('\n'.join([ solve(line.strip()) for line in stdin ]))