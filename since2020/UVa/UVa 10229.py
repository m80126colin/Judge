'''
	@judge UVa
	@id 10229
	@name Modular Fibonacci

	@tag Fibonacci Number, Exponentiation by Squaring, Matrix
'''
from sys import stdin

M = (1 << 20) - 1

def matMul(A, B):
	global M
	return [ [ sum([ A[i][k] * B[k][j] for k in range(2) ]) & M for j in range(2) ] for i in range(2) ]

Fs = [ [[ 0, 1 ], [ 1, 1 ]] ]
for _ in range(31):
	Fs.append(matMul(Fs[-1], Fs[-1]))

def solve(b):
	res = [ [ 1, 0 ], [ 0, 1 ] ]
	pos = 0
	while b > 0:
		if b & 1:
			res = matMul(res, Fs[pos])
		b >>= 1
		pos += 1
	return res[0][1]

for line in stdin:
	b, m = map(int, line.split())
	print(solve(b) & ((1 << m) - 1))