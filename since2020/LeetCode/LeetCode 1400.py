'''
	@judge LeetCode
	@id 1400
	@name Construct K Palindrome Strings
	@contest Biweekly Contest 23

	@tag Palindrome, Countings

	https://leetcode.com/problems/construct-k-palindrome-strings/
'''
from collections import Counter

class Solution:
	def canConstruct(self, s: str, k: int) -> bool:
		if len(s) < k:
			return False
		return [ x & 1 for x in Counter(s).values() ].count(1) <= k