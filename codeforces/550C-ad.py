'''
	CodeForces 550C
	Divisibility by Eight

	Tags: Math, Ad-hoc
'''
def solve(s, res):
	n = len(s)
	a = set([ s[i] for i in range(n) ])
	a1 = a & res
	if len(a1) > 0:
		return a1.pop()
	b = set([ s[i] + s[j] for i in range(n) for j in range(i + 1, n) ])
	b1 = b & res
	if len(b1) > 0:
		return b1.pop()
	c = set([ s[i] + s[j] + s[k] for i in range(n) for j in range(i + 1, n) for k in range(j + 1, n) ])
	c1 = c & res
	if len(c1) > 0:
		return c1.pop()

n   = input()
res = set([ str(x) for x in range(1001) if x % 8 == 0 ])

ans  = solve(n, res)
flag = ans is not None

print('YES' if flag else 'NO')
if flag:
	print(ans)