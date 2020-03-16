'''
	@judge UVa
	@id 12459
	@name Bees' ancestors

	@tag Fibonacci Number
'''
from sys import stdin

fib = [1, 1]
for _ in range(2, 81):
	fib.append(fib[-2] + fib[-1])

for line in stdin:
	n = int(line)
	if n == 0:
		break
	print(fib[n])