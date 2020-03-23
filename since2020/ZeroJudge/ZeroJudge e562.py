'''
	@judge ZeroJudge
	@id e562
	@name Triangle Counting
	@source UVa 11401

	@tag Math
'''
from sys import stdin

for line in stdin:
	n = int(line)
	if n >= 3:
		x = n // 2 - 1
		print(x * (x + 1) * (4 * x + (5 if n % 2 else -1)) // 6)