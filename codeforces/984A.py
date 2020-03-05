'''
	CodeForces 984A
	Game

	Tags: Sorting
'''
input()
res = sorted(map(int, input().split()))
print(res[(len(res) - 1) // 2])