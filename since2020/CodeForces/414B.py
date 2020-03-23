'''
	@judge CodeForces
	@id 414B
	@name Mashmokh and ACM

	@tag Dynamic Programming, Math
'''

MOD = 1000000007

n, k = map(int, input().split())

dp = [ [ 1 if j == 1 else 0 for j in range(k + 1) ] for i in range(n + 1) ]

for j in range(1, k):
	for i in range(1, n + 1):
		for ii in range(i, n + 1, i):
			dp[ii][j + 1] = (dp[ii][j + 1] + dp[i][j]) % MOD

ans = sum([ dp[i][k] for i in range(1, n + 1) ]) % MOD
print(ans)