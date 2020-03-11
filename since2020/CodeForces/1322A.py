'''
	@judge CodeForces
	@id 1322A
	@name Unusual Competitions
	@contest Codeforces Round #626

	@tag Greedy, Parentheses Matching
'''
from itertools import accumulate, starmap

input()
s = input()
p = list(accumulate(map(lambda p: 1 if p is '(' else -1, s)))

if p[-1] is not 0:
	print(-1)
else:
	point = [0] + list(map(lambda p: p[0] + 1, filter(lambda p: p[1] == 0, enumerate(p))))
	ans = sum(starmap(lambda a, b: b - a, filter(lambda seg: any(map(lambda n: n < 0, p[seg[0]:seg[1]])), zip(point, point[1:]))))
	print(ans)