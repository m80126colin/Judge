'''
	CodeForces 617A
	Elephant

	Tags: Math
'''
n = int(input())

print(n // 5 + (1 if n % 5 is not 0 else 0))