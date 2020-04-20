'''
	@judge LeetCode
	@id 1417
	@name Reformat The String
	@contest Weekly Contest 185

	@tag String Manipulation
'''
class Solution:
	def reformat(self, s: str) -> str:
		a = [ ch for ch in s if ord('a') <= ord(ch) and ord(ch) <= ord('z') ]
		b = [ ch for ch in s if ord('0') <= ord(ch) and ord(ch) <= ord('9') ]
		d = len(a) - len(b)
		if d < -1 or 1 < d:
			return ''
		return (b[-1] if d == -1 else '') + ''.join(map(lambda p: ''.join(p), zip(a, b))) + (a[-1] if d == 1 else '')