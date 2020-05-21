'''
	@judge LeetCode
	@id 442
	@name Find All Duplicates in an Array

	@tag Array
'''
class Solution:
	def findDuplicates(self, nums: List[int]) -> List[int]:
		res = []
		for idx in range(len(nums)):
			jdx = abs(nums[idx]) - 1
			if nums[jdx] < 0:
				res.append(jdx + 1)
			else:
				nums[jdx] *= -1
		return res