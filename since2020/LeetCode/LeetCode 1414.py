'''
	@judge LeetCode
	@id 1414
	@name Find the Minimum Number of Fibonacci Numbers Whose Sum Is K
	@contest Biweekly Contest 24

	@tag Fibonacci Number, Zeckendorf Representation
'''
class Solution:
	def findMinFibonacciNumbers(self, k: int) -> int:
		fib = [1, 2]
		for _ in range(43):
			fib.append(fib[-1] + fib[-2])
		res = 0
		for x in reversed(fib):
			if k > 0 and x <= k:
				k -= x
				res += 1
		return res