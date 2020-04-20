'''
	@judge LeetCode
	@id 386
	@name Lexicographical Numbers

	@tag Sortings
'''
class Solution:
	def lexicalOrder(self, n: int) -> List[int]:
		return sorted(range(1, n + 1), key=lambda x: str(x))