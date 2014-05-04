#include <cstdio>
#include <iostream>
using namespace std;

#define N  20130721LL
#define M  21679252LL

void matmul(long long a[2][2], long long b[2][2], long long c[2][2], long long m)
{
	int i, j, k;
	long long tmp[2][2] = {0};
	for (i = 0; i < 2; i++)
		for (j = 0; j < 2; j++)
		{
			for (k = 0; k < 2; k++)
				tmp[i][j] += a[i][k] * b[k][j];
			tmp[i][j] %= m;
		}
	for (i = 0; i < 2; i++)
		for (j = 0; j < 2; j++)
			c[i][j] = tmp[i][j];
	return ;
}

long long fibo(long long n, long long m)
{
	long long f[2][2] = {0}, ans[2][2] = {0};
	f[0][1] = f[1][0] = f[1][1] = 1;
	ans[0][0] = ans[1][1] = 1;
	for (; n; n >>= 1)
	{
		if (n & 1) matmul(ans, f, ans, m);
		matmul(f, f, f, m);
	}
	return ans[1][0];
}

int main()
{
	long long n;
	while (scanf("%lld", &n) != EOF)
		printf("%lld\n", fibo(fibo(n, M), N) );
	/*
	for (n = 0; true; n++)
	{
		long long res = fibo(n, N);
		if (res == 1) printf("n = %lld\n", n);
		if (n % 1000000 == 0) printf("===  n = %lld  ===\n", n);
	}
	*/
}