'''
	@judge LeetCode
	@id 5366
	@name Check if There is a Valid Path in a Grid
	@contest Weekly Contest 181

	@tag Breadth First Search
'''
class Solution:
	def hasValidPath(self, grid: List[List[int]]) -> bool:
		#
		path = [
			[],
			[(0,  1), (0, -1)],
			[(1,  0), (-1, 0)],
			[(0, -1), (1,  0)],
			[(0,  1), (1,  0)],
			[(-1, 0), (0, -1)],
			[(-1, 0), (0,  1)]
		]
		#
		ty = [
			[[], [1, 3, 5], [1, 4, 6]],
			[[2, 5, 6], []],
			[[2, 3, 4], []]
		]
		#
		n, m = len(grid), len(grid[0])
		visited = [ [ False for j in range(m) ] for i in range(n) ]
		#
		Q = [(0, 0)]
		while len(Q) > 0:
			x, y = Q.pop()
			visited[x][y] = True
			for dx, dy in path[grid[x][y]]:
				nx, ny = x + dx, y + dy
				if nx < 0 or nx >= n or ny < 0 or ny >= m:
					continue
				if grid[nx][ny] not in ty[dx][dy]:
					continue
				if visited[nx][ny] == False:
					Q.insert(0, (nx, ny))
		return visited[n - 1][m - 1]