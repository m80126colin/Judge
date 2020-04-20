'''
	@judge LeetCode
	@id 852
	@name Peak Index in a Mountain Array

	@tag Divide and Conquer
'''
class Solution:
	def findBinary(self, A: List[int], L: int, R: int) -> int:
		if L + 1 >= R:
			return L
		if L + 2 >= R:
			return L if A[L] > A[L + 1] else L + 1
		M = (L + R) // 2
		if A[M - 1] > A[M]:
			return self.findBinary(A, L, M)
		if A[M + 1] > A[M]:
			return self.findBinary(A, M + 1, R)
		return M
	def peakIndexInMountainArray(self, A: List[int]) -> int:
		return self.findBinary(A, 0, len(A))