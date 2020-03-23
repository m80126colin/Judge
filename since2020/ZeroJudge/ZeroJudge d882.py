'''
	@judge ZeroJudge
	@id d882
	@name The Priest Mathematician
	@source UVa 10254

	@tag Hanoi, Math, Dynamic Programming, Big Number
'''
from sys import stdin
from itertools import count

N = 10000
hanoi = [ 0 ]

for x in count(1):
	if len(hanoi) > N:
		break
	d = 1 << (x - 1)
	for y in range(x):
		hanoi.append(hanoi[-1] + d)

for line in stdin:
	print(hanoi[int(line)])