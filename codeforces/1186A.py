'''
	CodeForces 1186A
	Vus the Cossack and a Contest

	Tags: Ad-hoc
'''
n, m, k = tuple(map(int, input().split()))

print('Yes' if m >= n and k >= n else 'No')