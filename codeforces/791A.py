'''
	CodeForces 791A
	Bear and Big Brother

	Tags: Simulation
'''
def countYear(a, b):
	n = 0
	while a <= b:
		a *= 3
		b *= 2
		n += 1
	return n

ans = countYear(*tuple(map(int, input().split())))
print(ans)