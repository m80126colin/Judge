'''
	@judge LeetCode
	@id 1382
	@name Balance a Binary Search Tree
	@contest Weekly Contest 180

	@tag Binary Tree
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
	def infix(self, root: TreeNode) -> [int]:
		if root is None:
			return []
		L = self.infix(root.left)
		R = self.infix(root.right)
		return L + [ root.val ] + R
	
	def solve(self, arr: [int]) -> TreeNode:
		if len(arr) == 0:
			return None
		m = len(arr) // 2
		t = TreeNode(arr[m])
		t.left  = self.solve(arr[: m])
		t.right = self.solve(arr[m + 1 :])
		return t

	def balanceBST(self, root: TreeNode) -> TreeNode:
		r = self.solve(self.infix(root))
		# print(r)
		return r