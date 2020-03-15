'''
	@judge LeetCode
	@id 1381
	@name Design a Stack With Increment Operation
	@contest Weekly Contest 180

	@tag Stack, Simulation
'''
class CustomStack:
	def __init__(self, maxSize: int):
		self.size = maxSize
		self.data = []

	def push(self, x: int) -> None:
		if len(self.data) != self.size:
			self.data.append(x)

	def pop(self) -> int:
		if len(self.data) == 0:
			return -1
		D = self.data[-1]
		self.data = self.data[0:-1]
		return D

	def increment(self, k: int, val: int) -> None:
		pos = min(k, len(self.data))
		for x in range(0, pos):
			if x < len(self.data):
				self.data[x] += val