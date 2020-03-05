'''
	CodeForces 399A
	Pages

	Tags: Simulation
'''
n, p, k = list(map(int, input().split()))

L = max(p - k, 1)
R = min(p + k + 1, n + 1)

Larrow = ['<<'] if L is not 1 else list()
Rarrow = ['>>'] if R is not n + 1 else list()
middle = list(range(L, p)) + [f'({p})'] + list(range(p + 1, R))

res = Larrow + middle + Rarrow

print(*res)