'''
	@judge CodeForces
	@id 580B
	@name Kefa and Company

	@tag dp, Maximum Consecutive Sum
'''
from sys import stdin

def solve(people, d):
	ls   = sorted(people, key=lambda p: p[0])
	ans  = ls[0][1]
	acc  = 0
	last = -1
	for (idx, (m, s)) in enumerate(ls):
		while last >= 0 and idx - last > 0 and m - ls[last][0] >= d:
			acc -= ls[last][1]
			last += 1
		acc += s
		if last < 0 or idx - last <= 0:
			last = idx
		ans = max(ans, acc)
	return ans

n, d = tuple(map(int, input().split()))
friends = [ tuple(map(int, line.split())) for line in stdin.readlines() ]

ans = solve(friends, d)
print(ans)