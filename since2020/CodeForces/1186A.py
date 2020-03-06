'''
	@judge CodeForces
	@id 1186A
	@name Vus the Cossack and a Contest

	@tag Ad-hoc
'''
n, m, k = tuple(map(int, input().split()))

print('Yes' if m >= n and k >= n else 'No')