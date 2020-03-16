'''
	@judge ZeroJudge
	@id d283
	@name 大數加法

	@tag Big Number, Fibonacci Number
'''
from sys import stdin

fib = [0, 1]
for n in range(2, 20001):
	fib.append(fib[n - 1] + fib[n - 2])

for line in stdin:
	print(fib[int(line)])