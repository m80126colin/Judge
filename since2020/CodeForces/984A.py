'''
	@judge CodeForces
	@id 984A
	@name Game

	@tag Sorting
'''
input()
res = sorted(map(int, input().split()))
print(res[(len(res) - 1) // 2])