'''
	@judge LeetCode
	@id 1420
	@name Minimum Number of Frogs Croaking
	@contest Weekly Contest 185

	@tag Dynamic Programming
'''
class Solution:
	def numOfArrays(self, n: int, m: int, k: int) -> int:
		if k == 0:
			return 0
		MOD = 1000000007
		dp = [ [ [ 0 for _ in range(k + 1) ] for _ in range(m + 1) ] for _ in range(n + 1) ]
		for y in range(1, m + 1):
			dp[1][y][1] = dp[1][y - 1][1] + 1
		for x in range(2, n + 1):
			for y in range(1, m + 1):
				for kk in range(1, k + 1):
					dp[x][y][kk] += dp[x][y - 1][kk] + (dp[x - 1][y][kk] - dp[x - 1][y - 1][kk]) * y + dp[x - 1][y - 1][kk - 1]
					dp[x][y][kk] %= MOD
		ans = dp[n][m][k]
		return ans