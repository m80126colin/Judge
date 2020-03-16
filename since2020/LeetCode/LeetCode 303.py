'''
	@judge LeetCode
	@id 303
	@name Range Sum Query - Immutable

	@tag Range Query
'''
from itertools import accumulate

class NumArray:

	def __init__(self, nums: List[int]):
		self.data = list(accumulate(nums))

	def sumRange(self, i: int, j: int) -> int:
		if i == 0:
			return self.data[j]
		return self.data[j] - self.data[i - 1]