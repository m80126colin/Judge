'''
	@judge ZeroJudge
	@id a022
	@name 迴文

	@tag Palindrome, String Manipulation
'''
from sys import stdin

def isPalindrome(s):
	return all(map(lambda p: p[0] == p[1], zip(s, s[::-1])))

print('\n'.join([ 'yes' if isPalindrome(line.strip()) else 'no' for line in stdin ]))