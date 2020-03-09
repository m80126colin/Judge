'''
	@judge ZeroJudge
	@id a224
	@name 明明愛明明

	@tag Palindrome, Letter Frequency
'''
from collections import Counter
from sys import stdin

def solve(s):
	c = Counter(filter(lambda ch: ch.isalpha(), s.lower()))
	ans = list(map(lambda n: n & 1, c.values()))
	return 'yes !' if ans.count(1) <= 1 else 'no...'
	

print('\n'.join([ solve(line) for line in stdin ]))