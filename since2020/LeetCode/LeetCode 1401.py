'''
	@judge LeetCode
	@id 1401
	@name Circle and Rectangle Overlapping
	@contest Biweekly Contest 23

	@tag Geometry

	https://leetcode.com/problems/circle-and-rectangle-overlapping/
'''
class Solution:
	def checkOverlap(self, radius: int, x_center: int, y_center: int, x1: int, y1: int, x2: int, y2: int) -> bool:
		xr, yr = abs(2 * x_center - x1 - x2), abs(2 * y_center - y1 - y2)
		x, y   = max(xr - x2 + x1, 0), max(yr - y2 + y1, 0)
		return x ** 2 + y ** 2 <= 4 * radius ** 2