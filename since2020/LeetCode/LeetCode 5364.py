'''
	@judge LeetCode
	@id 5364
	@name Create Target Array in the Given Order
	@contest Weekly Contest 181

	@tag Simulation
'''
class Solution:
	def createTargetArray(self, nums: List[int], index: List[int]) -> List[int]:
		ans = []
		for i in range(len(nums)):
			if index[i] >= len(ans):
				ans.append(nums[i])
			else:
				ans = ans[:index[i]] + [ nums[i] ] + ans[index[i]:]
		return ans