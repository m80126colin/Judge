'''
	@judge CodeForces
	@id 580C
	@name Kefa and Park

	@tag dfs
'''
from sys import stdin

class Graph:
	def __init__(self, root, vertices, edges):
		self.size     = len(vertices)
		self.vertices = vertices
		self.edges    = list(map(lambda x: list(), range(self.size)))
		for (a, b) in edges:
			self.edges[a].append(b)
			self.edges[b].append(a)
		self.root   = root
		self.isleaf = list(map(lambda p: p[0] != root and len(p[1]) == 1, enumerate(self.edges)))

	def solve(self, m):
		ans   = 0
		label = [ (False, False) for x in range(self.size) ]
		stack = [ (self.root, 0) ]
		label[self.root] = (label[self.root][0], True)
		while len(stack) > 0:
			node, cats = stack.pop()
			label[node] = (True, False)
			flag = cats + 1 if self.vertices[node] == 1 else 0
			if self.isleaf[node]:
				if flag <= m:
					ans += 1
			elif flag <= m:
				for nxt in self.edges[node]:
					if label[nxt] == (False, False):
						stack.append((nxt, flag))
						label[nxt] = (label[nxt][0], True)
		return ans

def edgeMapping(line):
	a, b = tuple(map(int, line.split()))
	return a -1, b - 1

n, m    = tuple(map(int, input().split()))
verices = list(map(int, input().split()))
edges   = list(map(edgeMapping, stdin.readlines()))

graph = Graph(0, verices, edges)

print(graph.solve(m))