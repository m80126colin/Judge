'''
	@judge LeetCode
	@id 1380
	@name Lucky Numbers in a Matrix
	@contest Weekly Contest 180

	@tag Ad-hoc, Matrix
'''
class Solution:
	def luckyNumbers(self, matrix: List[List[int]]) -> List[int]:
		n, m = len(matrix), len(matrix[0])
		table = [ max([ matrix[i][j] for i in range(n) ]) for j in range(m) ]
		answer = []
		for i in range(n):
			mx = min(matrix[i])
			for j in range(m):
				if mx == matrix[i][j] and mx == table[j]:
					answer.append(mx)
		return answer