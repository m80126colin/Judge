'''
	@judge UVa
	@id 10579
	@name Fibonacci Numbers

	@tag Big Number, Fibonacci Number
'''
from sys import stdin

fib = [0, 1]
for _ in range(2, 5000):
	fib.append(fib[-1] + fib[-2])

for line in stdin:
	print(fib[int(line)])