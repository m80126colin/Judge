'''
	@judge LeetCode
	@id 144
	@name Binary Tree Preorder Traversal

	@tag Tree, Traversal
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
	def preorderTraversal(self, root: TreeNode) -> List[int]:
		if root == None:
			return []
		return [ root.val ] + self.preorderTraversal(root.left) + self.preorderTraversal(root.right)