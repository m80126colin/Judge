'''
	CodeForces 166E
	Tetrahedron

	Tags: Transition matrix
'''
MOD = 1000000007

def matrixMul(mat1, mat2):
	global MOD
	A = len(mat1)
	B = len(mat2)
	C = len(mat2[0])
	return [ [
		sum(map(lambda p: p[0] * p[1], zip(mat1[i], [ mat2[k][j] for k in range(B) ]))) % MOD
		for j in range(C) ]
	for i in range(A) ]


def matrixPow(mat, n):
	A = len(mat)
	result = [ [ 1 if i == j else 0 for j in range(A) ] for i in range(A) ]
	temp   = mat
	while n > 0:
		if n % 2 == 1:
			result = matrixMul(result, temp)
		temp = matrixMul(temp, temp)
		n //= 2
	return result

D   = 4
mat = [ [ 1 if i != j else 0 for j in range(D) ] for i in range(D) ]

n   = int(input())
ans = matrixPow(mat, n)[0][0]

print(ans)