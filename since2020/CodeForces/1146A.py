'''
	@judge CodeForces
	@id 1146A
	@name Love "A"

	@tag String manipulation
'''
s = input()
ans = len(s) - s.count('a') * 2

print(len(s) - ans - 1 if ans >= 0 else len(s))