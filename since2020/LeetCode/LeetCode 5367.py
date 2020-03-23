'''
	@judge LeetCode
	@id 5367
	@name Longest Happy Prefix
	@contest Weekly Contest 181

	@tag Pattern Matching
'''
class Solution:
	def longestPrefix(self, s: str) -> str:
		n = len(s)
		z = [-1] * n
		p = -1
		for idx in range(1, n):
			while s[p + 1] != s[idx] and p > -1:
				p = z[p]
			if s[p + 1] == s[idx]:
				p += 1
				z[idx] = p
		return s[:p + 1]