'''
	@judge CodeForces
	@id 1080A
	@name Petya and Origami

	@tag Math
'''
n, k = map(int, input().split())
ans  = sum(map(lambda x: (x * n + (k - 1)) // k, [2, 5, 8]))

print(ans)