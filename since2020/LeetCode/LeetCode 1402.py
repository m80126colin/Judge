'''
	@judge LeetCode
	@id 1402
	@name Reducing Dishes
	@contest Biweekly Contest 23

	@tag Linear Dynamic Programming, Countings

	https://leetcode.com/problems/reducing-dishes/
'''
from itertools import accumulate, takewhile

class Solution:
    def maxSatisfaction(self, satisfaction: List[int]) -> int:
        return sum(takewhile(lambda p: p > 0, accumulate(sorted(satisfaction, reverse=True))))