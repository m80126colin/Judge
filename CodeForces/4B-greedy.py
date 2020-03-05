'''
	CodeForces 4B
	Before an Exam

	Tags: Greedy
'''
from sys import stdin

d, s  = tuple(map(int, input().split()))
times = [ tuple(map(int, line.split())) for line in stdin.readlines() ]

mn, mx = tuple(map(sum, zip(*times)))
flag   = mn <= s and s <= mx

print('YES' if flag else 'NO')
if flag:
	ans = [ p[0] for p in times ]
	remain = s - sum(ans)
	for (idx, (n, x)) in enumerate(times):
		df = min(remain, x - n)
		ans[idx] += df
		remain -= df
	print(*ans)