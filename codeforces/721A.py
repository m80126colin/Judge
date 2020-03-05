'''
	CodeForces 721A
	One-dimensional Japanese Crossword

	Tags: String manipulation
'''
import re

input()
s = input()

ans = list(map(len, re.findall(r'B+', s)))

print(len(ans))
if len(ans) > 0:
	print(*ans)