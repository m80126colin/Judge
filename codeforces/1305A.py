'''
	CodeForces 1305A, Ozon Tech Challenge 2020
	Kuroni and the Gifts

	Tags: Sorting
'''
n = int(input())

for _ in range(n):
	input()
	arr1 = ' '.join(map(str, sorted(map(int, input().split()))))
	arr2 = ' '.join(map(str, sorted(map(int, input().split()))))
	print(arr1)
	print(arr2)