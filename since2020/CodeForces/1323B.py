'''
	@judge CodeForces
	@id 1323B
	@name Count Subrectangles
	@contest Codeforces Round #626

	@tag Tree Planting Problem
'''
from itertools import groupby

def getSection():
	return list(map(lambda p: len(list(p[1])), filter(lambda p: p[0] is '1', groupby(input().replace(' ', '')))))

def side(arr, x):
	return sum(map(lambda p: p - x + 1, filter(lambda p: p >= x, arr)))

n, m, k = map(int, input().split())
ass, bss = getSection(), getSection()

ans = sum([
	side(ass, x) * side(bss, k // x) +
	(side(bss, x) * side(ass, k // x) if x * x != k else 0)
		for x in range(1, int(k ** 0.5 + 0.5) + 1)
		if k % x == 0 ])

print(ans)