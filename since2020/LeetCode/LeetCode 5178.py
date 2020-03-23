'''
	@judge LeetCode
	@id 5178
	@name Four Divisors
	@contest Weekly Contest 181

	@tag Integer Factorisation
'''
from math import sqrt, ceil

class Solution:
	def count(self, n : int) -> int:
		tot = 1
		divisor = []
		for x in range(2, ceil(sqrt(n + 0.01))):
			cnt = 0
			while n % x == 0:
				cnt += 1
				n //= x
			if cnt >= 1:
				divisor.append((x, cnt))
				tot *= cnt + 1
			if tot > 4:
				return 0
		if n > 1:
			divisor.append((n, 1))
			tot *= 2
		if tot != 4:
			return 0
		if len(divisor) == 1:
			y = divisor[0][0]
			return 1 + y + y**2 + y**3
		y, z = divisor[0][0], divisor[1][0]
		return 1 + y + z + y * z

	def sumFourDivisors(self, nums: List[int]) -> int:
		return sum([ self.count(n) for n in nums ])