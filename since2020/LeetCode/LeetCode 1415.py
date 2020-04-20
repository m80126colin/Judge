'''
	@judge LeetCode
	@id 1415
	@name The k-th Lexicographical String of All Happy Strings of Length n
	@contest Biweekly Contest 24

	@tag Combinatorics
'''
class Solution:
	def getHappyString(self, n: int, k: int) -> str:
		M = 3 * (2 ** (n - 1))
		if k > M:
			return ''
		ls = list(reversed(list(map(lambda x: ((k - 1) // (2 ** x)) % 2, range(0, n - 1)))))
		ch = chr((k - 1) // (2 ** (n - 1)) + ord('a'))
		res = ch
		for x in ls:
			ch = chr(x + ord('a' if ch == 'c' or (ch == 'b' and x == 0) else 'b'))
			res += ch
		return res