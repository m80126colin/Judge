'''
	@judge LeetCode
	@id 1383
	@name Maximum Performance of a Team
	@contest Weekly Contest 180

	@tag Monotonicity, Heap
'''
import heapq

class Solution:
	def maxPerformance(self, n: int, speed: List[int], efficiency: List[int], k: int) -> int:
		arr = sorted(list(range(n)), key = lambda x: efficiency[x])
		HQ = []
		ans = 0
		s = 0
		for x in range(n - 1, -1, -1):
			if n - x > k:
				y = heapq.heappop(HQ)
				s -= y
			s += speed[arr[x]]
			heapq.heappush(HQ, speed[arr[x]])
			ans = max(ans, s * efficiency[arr[x]])
		return ans % 1000000007