'''
	@judge LeetCode
	@id 1377
	@name Frog Position After T Seconds

	@tag Tree Traversal, Probability

	https://leetcode.com/submissions/detail/311484743/
'''
class Solution:
	def frogPosition(self, n: int, edges: List[List[int]], t: int, target: int) -> float:
		N = n + 1
		graph = [ list() for _ in range(N) ]
		for u, v in edges:
			graph[u].append(v)
			graph[v].append(u)
		isleaf = [ True  ] * N
		inQ    = [ False ] * N
		dist   = [ -1    ] * N
		prob   = [ -1    ] * N
		dist[1] = 0
		prob[1] = 1
		Q = [ 1 ]
		inQ[1] = True
		while len(Q) > 0:
			node = Q.pop()
			p = len(list(filter(lambda x: inQ[x] == False, graph[node])))
			if p != 0:
				isleaf[node] = False
			for end in graph[node]:
				if inQ[end] == False:
					dist[end] = dist[node] + 1
					prob[end] = prob[node] * 1.0 / p
					Q.insert(0, end)
					inQ[end] = True
		if dist[target] > t or (dist[target] < t and isleaf[target] == False):
			return 0
		return prob[target]