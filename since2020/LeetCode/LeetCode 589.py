'''
	@judge LeetCode
	@id 589
	@name N-ary Tree Preorder Traversal

	@tag Tree, Traversal
'''

"""
# Definition for a Node.
class Node:
	def __init__(self, val=None, children=None):
		self.val = val
		self.children = children
"""

class Solution:
	def preorder(self, root: 'Node') -> List[int]:
		if root == None:
			return []
		res = [ root.val ]
		for child in root.children:
			res += self.preorder(child)
		return res