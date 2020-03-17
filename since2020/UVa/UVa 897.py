'''
	@judge UVa
	@id 897
	@name Anagrammatic Primes

	@tag Prime, Math
'''
from sys import stdin
from bisect import bisect_right

arr = [2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, 97, 113, 131, 199, 311, 337, 373, 733, 919, 991]

def solve(n):
	if n > arr[-1]:
		return 0
	m = arr[bisect_right(arr, n)]
	if len(str(n)) != len(str(m)):
		return 0
	return m

for line in stdin:
	n = int(line)
	if n != 0:
		print(solve(n))