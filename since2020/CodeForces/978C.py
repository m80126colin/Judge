'''
	@judge CodeForces
	@id 978C
	@name Letters

	@tag Binary Search
'''
from itertools import accumulate
from bisect import bisect_left

def solve(arr, n):
	pos = bisect_left(arr, n)
	return '{} {}'.format(pos + 1, n - (arr[pos - 1] if pos > 0 else 0))

n, m = map(int, input().split())
ass  = list(accumulate(map(int, input().split())))

ans = '\n'.join([ solve(ass, x) for x in map(int, input().split()) ])
print(ans)