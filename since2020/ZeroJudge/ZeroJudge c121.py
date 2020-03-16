'''
	@judge ZeroJudge
	@id c121
	@name Fibonacci Numbers
	@source UVa 495

	@tag Big Number, Fibonacci Number
'''
from sys import stdin

fib = [0, 1]
for _ in range(2, 5001):
	fib.append(fib[-1] + fib[-2])

for line in stdin:
	n = int(line)
	print(f'The Fibonacci number for {n} is {fib[n]}')