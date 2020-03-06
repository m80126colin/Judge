'''
	CodeForce 1300A
	Non-zero
	
	Tags: Math, Ad-hoc
'''
t = int(input())

for i in range(t):
	input()
	arr  = list(map(int, input().split()))
	zero = arr.count(0)
	tot  = sum(arr) + zero

	print(zero + int(tot == 0))