'''
	@judge CodeForces
	@id 263A
	@name Beautiful Matrix

	@tag Math
'''
mat = [ (x, input().find('1') // 2) for x in range(5) ]
ans = [ abs(x - 2) + abs(y - 2) for (x, y) in mat if y >= 0 ]

print(ans[0])