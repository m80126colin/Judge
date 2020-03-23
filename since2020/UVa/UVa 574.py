'''
	@judge UVa
	@id 574
	@name Sum It Up

	@tag Subset Sum
'''
from sys import stdin
from itertools import chain, dropwhile

def answer(arr, t):
	if t == 0:
		return [[]]
	if t < 0 or len(arr) == 0:
		return []
	cnt = arr.count(arr[0])
	brr = list(dropwhile(lambda x: x == arr[0], arr))
	s = [ [ arr[0] ] * x + ls for x in range(cnt, -1, -1) for ls in answer(brr, t - x * arr[0]) ]
	return s

def solve(arr, t):
	s = answer(arr, t)
	if len(s) == 0:
		return 'NONE'
	return '\n'.join(map(lambda ls: '+'.join(map(str, ls)), s))

for line in stdin:
	t, n, *arr = map(int, line.split())
	if n == 0:
		break
	print(f'Sums of {t}:')
	print(solve(arr, t))