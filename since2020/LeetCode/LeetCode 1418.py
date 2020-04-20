'''
	@judge LeetCode
	@id 1418
	@name Display Table of Food Orders in a Restaurant
	@contest Weekly Contest 185

	@tag Ad-hoc, Distinct Item
'''
class Solution:
	def displayTable(self, orders: List[List[str]]) -> List[List[str]]:
		d = dict()
		for p in orders:
			if p[1] not in d:
				d[p[1]] = dict()
			if p[2] not in d[p[1]]:
				d[p[1]][p[2]] = 0
			d[p[1]][p[2]] += 1
		keys = sorted(list(set([ p[2] for p in orders ])))
		nums = sorted(d.keys(), key=lambda x: int(x))
		res = []
		res.append(['Table'] + keys)
		for num in nums:
			arr = [ d[num][key] if key in d[num] else 0 for key in keys ]
			res.append(list(map(lambda x: str(x), [ num ] + arr)))
		return res