'''
	@judge CodeForces
	@id 393A
	@name Nineteen

	@tag Counting
'''
from collections import Counter

s = input()
m = Counter(s)

if m['n'] < 3:
  	print(0)
else:
	print(min((m['n'] - 1) // 2, m['e'] // 3, m['t'], m['i']))