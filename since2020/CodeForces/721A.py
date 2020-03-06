'''
	@judge CodeForces
	@id 721A
	@name One-dimensional Japanese Crossword

	@tag String manipulation
'''
import re

input()
s = input()

ans = list(map(len, re.findall(r'B+', s)))

print(len(ans))
if len(ans) > 0:
	print(*ans)