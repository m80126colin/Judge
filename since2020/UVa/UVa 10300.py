'''
	@judge UVa
	@id 10300
	@name Ecological Premium

	@tag Binary Operations
'''
from functools import reduce

for _ in range(int(input())):
	f = int(input())
	ans = reduce(lambda p, x: p + int(x[0]) * int(x[-1]), map(lambda _: input().split(), range(f)), 0)
	print(ans)