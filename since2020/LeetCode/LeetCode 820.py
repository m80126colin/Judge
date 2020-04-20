'''
	@judge LeetCode
	@id 820
	@name Short Encoding of Words

	@tag String Manipulation, Monotonicity, Lexicographical order
'''
class Solution:
	def minimumLengthEncoding(self, words: List[str]) -> int:
		ls = sorted(map(lambda s: s[::-1], words))
		it = iter(ls)
		next(it)
		return sum(map(lambda p: len(p[0]) + 1, filter(lambda p: p[1].startswith(p[0]) == False, zip(ls, it)))) + len(ls[-1]) + 1