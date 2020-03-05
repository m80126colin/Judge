'''
	CodeForces 978B
	File Name

	Tags: String manipulation
'''
import re

n = int(input())
s = input()

ans = sum(map(lambda x: len(x) - 2, re.findall(r'xxx+', s)))
print(ans)