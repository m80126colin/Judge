'''
	CodeForces 1136A
	Nastya Is Reading a Book

	Tags: Counting
'''
n = int(input())
chapters = list(map(lambda x: int(input().split()[-1]), range(n)))
k = int(input())

ans = len(list(filter(lambda p: p >= k, chapters)))
print(ans)