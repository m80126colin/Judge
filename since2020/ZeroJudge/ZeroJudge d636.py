'''
	@judge ZeroJudge
	@id d636
	@name 大爆炸bomb

	@tag Exponentiation by Squaring
'''
from sys import stdin

def solve(a, b):
	MOD = 10007
	ans = 1
	while b > 0:
		if b & 1:
			ans = (ans * a) % MOD
		a = (a * a) % MOD
		b >>= 1
	return ans

for line in stdin:
	a, b = map(int, line.split())
	print(solve(a, b))