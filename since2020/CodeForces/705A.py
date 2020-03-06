'''
	@judge CodeForces
	@id 705A
	@name Hulk

	@tag String Manipulation
'''
n = int(input())

temp = [ 'I hate' if x % 2 == 0 else 'I love' for x in range(n) ]
res  = '{} it'.format(' that '.join(temp))

print(res)