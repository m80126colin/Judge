'''
	@judge UVa
	@id 1644
	@name Prime Gap

	@tag Prime
'''
from sys import stdin
from itertools import takewhile, count

def isp(n):
	return all(map(lambda x: n % x != 0, takewhile(lambda x: x * x <= n, count(2))))

def solve(k):
	if isp(k):
		return 0
	a = max(takewhile(lambda x: k - x > 0 and isp(k - x) == False, count(0)))
	b = max(takewhile(lambda x: isp(k + x) == False, count(0)))
	return a + b + 2

for line in stdin:
	k = int(line)
	if k != 0:
		print(solve(k))