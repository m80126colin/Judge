'''
	@judge CodeForces
	@id 1327A
	@name Sum of Odd Integers
	@contest Educational Codeforces Round 84

	@tag Math
'''
from sys import stdin

def solve(n, k):
	if k * k > n:
		return False
	return n % 2 == k % 2

input()
for line in stdin:
	n, k = map(int, line.split())
	print('YES' if solve(n, k) else 'NO')