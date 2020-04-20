'''
	@judge CodeForces
	@id 1328B
	@name K-th Beautiful String
	@contest Codeforces Round #629 (Div. 3)

	@tag Combination & Permutaion
'''
from sys import stdin
from bisect import bisect_left

N = 100010
triangular = [ 0 ]
for n in range(1, N):
	triangular.append(triangular[-1] + n)

def solve(n, k):
	pos = bisect_left(triangular, k)
	b1 = n - pos - 1
	b2 = b1 + triangular[pos] - k + 1
	return 'a' * b1 + 'b' + 'a' * (b2 - b1 - 1) + 'b' + 'a' * (n - b2 - 1)

input()
for line in stdin:
	n, k = map(int, line.split())
	print(solve(n, k))