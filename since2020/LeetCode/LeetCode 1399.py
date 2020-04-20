'''
	@judge LeetCode
	@id 1399
	@name Count Largest Group
	@contest Biweekly Contest 23

	@tag Ad-hoc

	https://leetcode.com/problems/count-largest-group/
'''
from itertools import groupby

class Solution:
	def ss(self, n: int) -> int:
		res = 0
		while n > 0:
			res += n % 10
			n //= 10
		return res
	def countLargestGroup(self, n: int) -> int:
		ls = list(map(lambda p: len(list(p[1])), groupby(sorted(range(1, n + 1), key=self.ss), key=self.ss)))
		mx = max(ls)
		return ls.count(mx)