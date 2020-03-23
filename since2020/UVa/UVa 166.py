'''
	@judge UVa
	@id 166
	@name Making Change

	@tag Bounded Knapsack, Greedy, Change-making
'''
from sys import stdin

coin = [1, 2, 4, 10, 20, 40]

def bounded(num):
	M = sum(num) + 1
	N = sum(map(lambda p: p[0] * p[1], zip(num, coin))) + 1
	dp = [ M ] * N
	# Bounded Knapsack
	dp[0] = 0
	for idx, c in enumerate(coin):
		for pos in range(N - c - 1, -1, -1):
			for x in range(1, num[idx] + 1):
				target = pos + x * c
				if target < N:
					dp[target] = min(dp[target], dp[pos] + x)
	return dp, N, M

def greedy(money):
	ans = 0
	for c in reversed(coin):
		if money > 0 and money >= c:
			n = money // c
			ans += n
			money -= n * c
	return ans

def solve(num, money):
	dp, N, M = bounded(num)
	return min([ dp[t] + greedy(t - money) for t in range(money, N) if dp[t] < M ])

for line in stdin:
	*num, money = line.split()
	num = list(map(int, num))
	if sum(num) != 0:
		print('{:>3}'.format(solve(num, int(float(money) * 100 + 0.01) // 5)))