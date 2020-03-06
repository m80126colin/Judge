'''
	@judge CodeForces
	@id 1006A
	@name Adjacent Replacements

	@tag Ad-hoc
'''
input()
ans = map(lambda x: x - 1 if x % 2 is 0 else x, map(int, input().split()))

print(*ans)