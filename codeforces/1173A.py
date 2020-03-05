'''
	CodeForces 1173A
	Nauuo and Votes

	Tags: Ad-hoc, Math
'''
def sign(n):
	if n > 0:
		return 1
	if n < 0:
		return -1
	return 0

x, y, z = map(int, input().split())
up   = sign(x - y + z)
down = sign(x - y - z)

if up * down > 0:
	print('+' if up > 0 else '-')
elif up is 0 and down is 0:
	print('0')
else:
	print('?')