'''
	@judge ZeroJudge
	@id a022
	@name 迴文

	@tag Palindrome, String Manipulation
'''
from sys import stdin

def isPalindrome(s):
	return s == s[::-1]

print('\n'.join([ 'yes' if isPalindrome(line.strip()) else 'no' for line in stdin ]))