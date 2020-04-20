'''
	@judge LeetCode
	@id 145
	@name Binary Tree Postorder Traversal

	@tag Tree, Traversal
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
	def postorderTraversal(self, root: TreeNode) -> List[int]:
		if root == None:
			return []
		return self.postorderTraversal(root.left) + self.postorderTraversal(root.right) + [ root.val ]