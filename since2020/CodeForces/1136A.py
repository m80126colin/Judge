'''
	@judge CodeForces
	@id 1136A
	@name Nastya Is Reading a Book

	@tag Counting
'''
n = int(input())
chapters = list(map(lambda x: int(input().split()[-1]), range(n)))
k = int(input())

ans = len(list(filter(lambda p: p >= k, chapters)))
print(ans)