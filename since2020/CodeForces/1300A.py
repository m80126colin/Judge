'''
	@judge CodeForces
	@id 1300A
	@name Non-zero
	
	@tag Math, Ad-hoc
'''
t = int(input())

for i in range(t):
	input()
	arr  = list(map(int, input().split()))
	zero = arr.count(0)
	tot  = sum(arr) + zero

	print(zero + int(tot == 0))