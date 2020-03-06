'''
	@judge CodeForces
	@id 1305A
	@name Kuroni and the Gifts
	@contest Ozon Tech Challenge 2020

	@tag Sorting
'''
n = int(input())

for _ in range(n):
	input()
	arr1 = ' '.join(map(str, sorted(map(int, input().split()))))
	arr2 = ' '.join(map(str, sorted(map(int, input().split()))))
	print(arr1)
	print(arr2)