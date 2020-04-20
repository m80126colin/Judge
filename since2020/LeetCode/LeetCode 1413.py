'''
	@judge LeetCode
	@id 1413
	@name Minimum Value to Get Positive Step by Step Sum
	@contest Biweekly Contest 24

	@tag Math
'''
from itertools import accumulate

class Solution:
	def minStartValue(self, nums: List[int]) -> int:
		return max(-min(accumulate(nums)) + 1, 1)