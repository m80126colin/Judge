'''
	@judge CodeForces
	@id 1327C
	@name Game with Chips
	@contest Educational Codeforces Round 84

	@tag Ad-hoc
'''
n, m, k = map(int, input().split())

left  = 'D' + 'L' * (m - 1)
right = 'D' + 'R' * (m - 1)

ans = ''.join([ 'U' * (n - 1), 'L' * (m - 1), 'R' * (m - 1) ] + [ left if x % 2 == 0 else right for x in range(n - 1) ])
print(len(ans))
print(ans)