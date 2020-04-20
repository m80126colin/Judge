'''
	@judge LeetCode
	@id 820
	@name Find Peak Element

	@tag Divide and Conquer
'''
class Solution:
	def findBinary(self, nums: List[int], L: int, R: int):
		if L + 1 >= R:
			return L
		if L + 2 >= R:
			return L if nums[L] > nums[L + 1] else L + 1
		M = (L + R) // 2
		idxL = self.findBinary(nums, L, M)
		idxR = self.findBinary(nums, M + 1, R)
		if idxL + 1 < M or nums[idxL] > nums[M]:
			return idxL
		if idxR - 1 > M or nums[idxR] > nums[M]:
			return idxR
		return M
	def findPeakElement(self, nums: List[int]) -> int:
		return self.findBinary(nums, 0, len(nums))