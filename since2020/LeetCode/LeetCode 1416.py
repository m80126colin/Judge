'''
	@judge LeetCode
	@id 1416
	@name Restore The Array
	@contest Biweekly Contest 24

	@tag Linear Dynamic Programming
'''
class Solution:
	def numberOfArrays(self, s: str, k: int) -> int:
		sL = len(s)
		L = len(str(k))
		dp = [ 1 ] + [ 0 ] * sL
		for x in range(1, sL + 1):
			for y in range(1, min(x, L) + 1):
				if s[x - y] != '0' and int(s[x - y:x]) <= k:
					dp[x] += dp[x - y]
					dp[x] %= 1000000007
		return dp[-1]