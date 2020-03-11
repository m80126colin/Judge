'''
	@judge CodeForces
	@id 1323A
	@name Even Subset Sum Problem
	@contest Codeforces Round #626

	@tag Ad-hoc
'''
def solve(arr):
	even = next(iter(filter(lambda x: x[1] % 2 == 0, enumerate(arr))), None)
	if even is not None:
		print('1')
		print(even[0] + 1)
		return
	if len(arr) > 1:
		print('2')
		print('1 2')
		return
	print('-1')

for _ in range(int(input())):
	input()
	arr = list(map(int, input().split()))
	solve(arr)