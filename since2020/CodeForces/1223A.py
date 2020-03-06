'''
	CodeForces 1223A
	CME

	Tags: Math
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