'''
	@judge CodeForces
	@id 1324C
	@name Frog Jumps
	@contest Codeforces Round #627
	
	@tag Greedy, Minimax Problem
'''
from sys import stdin

input()
for line in stdin:
	s = line.strip()
	arr = [0] + [ idx + 1 for idx, ch in enumerate(s) if ch == 'R' ] + [ len(s) + 1 ]
	it = iter(arr)
	next(it)
	ans = max(map(lambda p: p[1] - p[0], zip(iter(arr), it)))
	print(ans)