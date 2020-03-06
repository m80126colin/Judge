'''
	@judge CodeForces
	@id 1223A
	@name CME

	@tag Math
'''
def solve(n):
	if n < 4:
		return 4 - n
	if n % 2 is 0:
		return 0
	return 1

q   = int(input())
res = [ str(solve(int(input()))) for x in range(q) ]

print('\n'.join(res))