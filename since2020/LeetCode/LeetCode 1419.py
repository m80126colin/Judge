'''
	@judge LeetCode
	@id 1419
	@name Minimum Number of Frogs Croaking
	@contest Weekly Contest 185

	@tag Segment
'''
from itertools import accumulate
from collections import Counter

class Solution:
	def isCountValid(self, s):
		c = Counter(s)
		if c['c'] != c['r'] or c['c'] != c['o'] or c['c'] != c['a'] or c['c'] != c['k']:
			return False
		return True
	def minNumberOfFrogs(self, croakOfFrogs: str) -> int:
		d = dict([ ('c', 0), ('r', 1), ('o', 2), ('a', 3), ('k', 4) ])
		if self.isCountValid(croakOfFrogs) == False:
			return -1
		pack = [ [], [], [], [], [] ]
		for p in enumerate(croakOfFrogs):
			pack[d[p[1]]].append(p[0])
		L = len(pack[0])
		for x in range(4):
			for y in range(L):
				if pack[x][y] >= pack[x + 1][y]:
					return -1
		ans = max(accumulate(map(lambda p: p[1], sorted([ (pack[0][y], 1) for y in range(L) ] + [ (pack[-1][y], -1) for y in range(L) ], key=lambda p: p[0]))))
		return ans