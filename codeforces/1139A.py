'''
	CodeForces 1139A
	Even Substrings

	Tags: String, Manipulation
'''

input()
s = input()
ans = sum(map(lambda x: x[0] + 1 if int(x[1]) % 2 == 0 else 0, enumerate(s)))
print(ans)