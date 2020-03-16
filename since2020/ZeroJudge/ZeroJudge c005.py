'''
	@judge ZeroJudge
	@id c005
	@name Ecological Premium
	@source UVa 10300

	@tag Binary Operations
'''
from functools import reduce

for _ in range(int(input())):
	f = int(input())
	ans = reduce(lambda p, x: p + int(x[0]) * int(x[-1]), map(lambda _: input().split(), range(f)), 0)
	print(ans)