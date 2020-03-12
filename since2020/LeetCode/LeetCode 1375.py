'''
	@judge LeetCode
	@id 1375
	@name Bulb Switcher III

	@tag Sortings

	https://leetcode.com/submissions/detail/311475105/
'''
class Solution:
	def numTimesAllBlue(self, light: List[int]) -> int:
		ls = sorted(enumerate(light), key=lambda p: p[1])
		ans = 0
		t = 0
		for idx, blub in ls:
			t = max(t, idx)
			if t < blub:
				ans += 1
		return ans