'''
	@judge LeetCode
	@id 590
	@name N-ary Tree Postorder Traversal

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
	def postorder(self, root: 'Node') -> List[int]:
		if root == None:
			return []
		res = []
		for child in root.children:
			res += self.postorder(child)
		return res + [ root.val ]