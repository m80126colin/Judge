'''
	@judge ZeroJudge
	@id d038
	@name Brick Wall Patterns
	@source UVa 900

	@tag Fibonacci Number, Linear Dynamic Programming
'''
from sys import stdin

N = 50
fib = [1, 1]
for _ in range(2, N + 1):
	fib.append(fib[-1] + fib[-2])

for line in stdin:
	n = int(line)
	if n == 0:
		break
	print(fib[n])