'''
	@judge ZeroJudge
	@id d261
	@name Bee
	@source UVa 11000

	@tag Fibonacci Number, Dynamic Programming
'''
from sys import stdin

fib = [1, 1]
while fib[-1] < (1 << 32):
	fib.append(fib[-2] + fib[-1])

for line in stdin:
	n = int(line)
	if n < 0:
		break
	print(fib[n + 1] - 1, fib[n + 2] - 1)