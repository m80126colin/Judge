'''
	@judge LeetCode
	@id 1374
	@name Generate a String With Characters That Have Odd Counts

	@tag String Manipulation

	https://leetcode.com/submissions/detail/311473927/
'''
class Solution:
	def generateTheString(self, n: int) -> str:
		if n % 2 == 0:
			return 'a' * 1 + 'b' * (n - 1)
		return 'a' * n