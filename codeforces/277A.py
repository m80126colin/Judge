'''
	CodeForces 277A
	Learning Languages

	Tags: Disjoint forest
'''
from sys import stdin

class Forest:
	def __init__(self, s):
		self.forest = [ i for i in range(s) ]
		self.group  = [ 1 for i in range(s) ]
		self.size   = s
	
	def find(self, x):
		if self.forest[x] != x:
			self.forest[x] = self.find(self.forest[x])
		return self.forest[x]
	
	def union(self, x, y):
		a = self.find(x)
		b = self.find(y)
		if a != b:
			self.forest[a] = b
			self.group[b] += self.group[a]
	
	def leader(self):
		return [ (x, self.group[x]) for x in range(self.size) if self.forest[x] == x ]

n, m = map(int, input().split())
employees = [ list(map(int, line.split()))[1:] for line in stdin.readlines() ]

forest = Forest(n + m)

for (p, em) in enumerate(employees):
	for x in em:
		forest.union(p, n + x - 1)

leader = forest.leader()
group  = list(filter(lambda x: x[1] > 1, leader))
indep  = list(filter(lambda x: len(x) == 0, employees))

ans = len(group) - (1 if len(group) >= 1 else 0) + len(indep)

print(ans)