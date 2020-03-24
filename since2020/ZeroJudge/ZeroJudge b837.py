'''
	@judge ZeroJudge
	@id b837
	@name 104北二1費氏數列

	@tag Fibonacci Number, Binary Search
'''
from sys import stdin
from itertools import chain
from bisect import bisect_left, bisect_right

fib = [0, 1]
while fib[-1] < 1000000:
	fib.append(fib[-2] + fib[-1])

def solve(A, B):
	A, B = min(A, B), max(A, B)
	L, R = bisect_left(fib, A), bisect_right(fib, B)
	return '\n'.join(chain(map(lambda idx: str(fib[idx]), range(L, R)), [ f'{R - L}' ]))

input()
print('\n------\n'.join([solve(*map(int, line.split())) for line in stdin ]))