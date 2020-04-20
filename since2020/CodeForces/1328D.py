'''
	@judge CodeForces
	@id 1328D
	@name Carousel
	@contest Codeforces Round #629 (Div. 3)

	@tag Greedy, Cycle Detecting
'''
from sys import stdin

def isSame(ts):
	it = iter(ts)
	next(it)
	return all(map(lambda p: p[0] == p[1], zip(iter(ts), it)))

def oddRingStart(n, ts):
	for x in range(0, n):
		if ts[x] == ts[(x + 1) % n]:
			return x
	return -1

def solve(n, ts):
	if isSame(ts):
		return '1', ['1'] * n
	if n % 2 == 0:
		return '2', [ 1, 2 ] * (n // 2)
	pos = oddRingStart(n, ts)
	if pos == -1:
		return '3', [1, 2] * (n // 2) + [3]
	res = [1, 2] * (n // 2) + [1]
	L = len(res) - pos - 1
	return '2', res[L:] + res[:L]

input()
for a, b in zip(*[ iter(stdin) ] * 2):
	n  = int(a)
	ts = list(map(int, b.split()))
	T, res = solve(n, ts)
	print(T)
	print(*res)