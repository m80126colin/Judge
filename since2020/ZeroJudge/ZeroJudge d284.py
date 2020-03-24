'''
	@judge ZeroJudge
	@id d284
	@name Combinations

	@tag Combinatorics, Combinatorics Dynamic Programming, Big Number

	@prove
		dp[n]
		= sum([ C(n, i) * (9 ** (n - i)) for i in range(0, n + 1, 2) ])
		= sum([ C(n - 1, 0) * (9 ** n) ] +
		      [ (C(n - 1, i - 1) + C(n - 1, i)) * (9 ** (n - i)) for i in range(2, n, 2) ] +
			  ([ C(n - 1, n - 1) * (9 ** 0) ] if n % 2 == 0 else []))
		= sum([ (8 + 1) * C(n - 1, 0) * (9 ** (n - 1)) ] +
		      [ C(n - 1, i - 1) * (9 ** (n - i)) + (8 + 1) * C(n - 1, i) * (9 ** (n - i - 1)) for i in range(2, n, 2) ] +
			  ([ C(n - 1, n - 1) * (9 ** 0) ] if n % 2 == 0 else []))
		= sum([ 8 * C(n - 1, i) * (9 ** (n - i - 1)) for i in range(0, n, 2) ] +
			  [ C(n - 1, j) * (9 ** (n - 1 - j)) for j in range(n) ])
		= 8 * sum([ C(n - 1, i) * (9 ** (n - i - 1)) for i in range(0, n, 2) ]) + (10 ** (n - 1))
		= 8 * dp[n - 1] + (10 ** (n - 1))

		dp[n] = (2 ** (n - 1)) * (4 ** n + 5 ** n)
'''
from sys import stdin
from functools import reduce

N = 100
dp = [ 1 ]
for n in range(1, N + 1):
	dp.append(dp[-1] * 8 + 10 ** (n - 1))

def solve(n):
	return dp[n]

for line in stdin:
	n = int(line)
	if n == 0:
		break
	print(solve(n))