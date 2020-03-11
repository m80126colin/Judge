'''
	@judge CodeForces
	@id 984A
	@name Game

	@tag Sortings
'''
input()
res = sorted(map(int, input().split()))
print(res[(len(res) - 1) // 2])