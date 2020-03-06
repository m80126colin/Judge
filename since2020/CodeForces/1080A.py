'''
	CodeForce 1080A
	Petya and Origami

	Tags: Math
'''
n, k = map(int, input().split())
ans  = sum(map(lambda x: (x * n + (k - 1)) // k, [2, 5, 8]))

print(ans)