'''
	@judge CodeForces
	@id 1316C
	@name Primitive Primes
	@contest CodeCraft-20 (Div. 2)

	@tag Math, Prime, Polynomial
'''
def findIndex(arr, p):
	return max(map(lambda px: px[0], filter(lambda px: px[1] % p, enumerate(arr))))

n, m, p = map(int, input().split())
ass = list(map(int, input().split()))
bss = list(map(int, input().split()))

print(findIndex(ass, p) + findIndex(bss, p))