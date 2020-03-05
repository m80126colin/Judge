'''
	CodeForces 1284A
	New Year and Naming

	Tags: Math
'''
def solve(x, n, m, L1, L2):
	return L1[(x - 1) % n] + L2[(x - 1) % m]

n, m = tuple(map(int, input().split()))
ns = input().split()
ms = input().split()
q = int(input())

ans = [ solve(int(input()), n, m, ns, ms) for x in range(q) ]
print('\n'.join(ans))