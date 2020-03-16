'''
	@judge ZeroJudge
	@id a134
	@name Fibonaccimal Base
	@source UVa 948

	@tag Fibonacci Number, Number Base Conversion, Zeckendorf Representation
'''
from sys import stdin
from bisect import bisect_right

fib = [1, 2]
while fib[-1] < 100000000:
	fib.append(fib[-2] + fib[-1])

def solve(n):
	if n == 0:
		return '0'
	ans  = ''
	for x in range(bisect_right(fib, n) - 1, -1, -1):
		if n >= fib[x]:
			n -= fib[x]
			ans += '1'
		else:
			ans += '0'
	return ans

input()
for line in stdin:
	n = int(line)
	f = solve(n)
	print(f'{n} = {f} (fib)')