'''
	CodeForces 1017A
	The Rank

	Tags: Search
'''
from sys import stdin
from bisect import bisect_left

input()
students = list(map(lambda line: -sum(map(int, line.split())), stdin.readlines()))
ans = bisect_left(sorted(students[1:]), students[0]) + 1

print(ans)