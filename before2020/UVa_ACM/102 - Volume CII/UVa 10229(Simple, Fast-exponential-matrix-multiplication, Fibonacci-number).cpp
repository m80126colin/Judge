/**
 *  @judge UVa
 *  @id 10229
 *  @tag Simple, Fast exponential matrix multiplication, Fibonacci number
 */
#include <stdio.h>
#include <iostream>
#define M ((1 << 20) - 1)
using namespace std;

class Matrix
{
public:
	long long en[2][2];
	Matrix operator * (const Matrix& B)
	{
		Matrix C;
		int i, j, k;
		for (i = 0; i < 2; i++)
			for (j = 0; j < 2; j++)
			{
				C.en[i][j] = 0;
				for (k = 0; k < 2; k++)
					C.en[i][j] += en[i][k] * B.en[k][j];
				C.en[i][j] &= M;
			}
		return C;
	}
	Matrix& operator *= (const Matrix& B)
	{
		(*this) = (*this) * B;
		return (*this);
	}
}EM, Fibo, Ans;

int main()
{
	int i, j, m;
	long long it, n;
	for (i = 0; i < 2; i++)
		for (j = 0; j < 2; j++)
			EM.en[i][j] = 1;
	EM.en[1][1] = 0;
	while (scanf("%lld%d", &n, &m) != EOF)
	{
		Fibo = EM;
		Ans.en[0][0] = Ans.en[1][1] = 1;
		Ans.en[0][1] = Ans.en[1][0] = 1;
		n--;
		for (it = 1; it <= n; it <<= 1)
		{
			if (n & it) Ans *= Fibo;
			Fibo *= Fibo;
		}
		if (n < 0) puts("0");
		else printf("%lld\n", Ans.en[1][1] & ((1 << m) - 1));
	}
}