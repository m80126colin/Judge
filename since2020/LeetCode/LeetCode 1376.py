'''
	@judge LeetCode
	@id 1376
	@name Time Needed to Inform All Employees

	@tag Tree Traversal

	https://leetcode.com/submissions/detail/311481829/
'''
class Solution:
	def numOfMinutes(self, n: int, headID: int, manager: List[int], informTime: List[int]) -> int:
		informer = [ -1 ] * n
		informer[headID] = informTime[headID]
		for employ in range(n):
			if informTime[employ] != 0 and informer[employ] == -1:
				path = [ employ ]
				node = employ
				while informer[manager[node]] == -1:
					parent = manager[node]
					path.append(parent)
					node = parent
				for node in reversed(path):
					informer[node] = informer[manager[node]] + informTime[node]
		ans = max([ informer[employ] for employ in range(n) if informer[employ] >= 0 ])
		return ans