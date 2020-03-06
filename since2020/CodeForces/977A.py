'''
	@judge CodeForces
	@id 977A
	@name Wrong Subtraction

	@tag Simulation
'''
n, k = tuple(map(int, input().split()))

while k > 0:
	tail = n % 10
	if k < tail + 1:
		n -= k
		k = 0
	else:
		n //= 10
		k -= tail + 1

print(n)