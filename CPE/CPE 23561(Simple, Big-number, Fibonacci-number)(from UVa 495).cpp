#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

struct Bigint
{
#define MAX 1010
#define NMAX 4
#define NN 10000
	int a[MAX];
	Bigint() {
		memset(a, 0, sizeof(a));
	}
	Bigint& operator = (const int &b)
	{
		memset(a, 0,sizeof(a));
		int i;
		a[0] = b;
		for (i = 0; a[i] != 0; i++)
		{
			if (a[i] >= NN)
			{
				a[i + 1] += a[i] / NN;
				a[i] %= NN;
			}
		}
		return (*this);
	}
	Bigint operator + (const Bigint & b)
	{
		int i;
		Bigint A;
		A = (*this);
		for (i = 0; i < MAX; i++)
		{
			A.a[i] += b.a[i];
		}
		for (i = 0; i < MAX - 1; i++)
		{
			if (A.a[i] >= NN)
			{
				A.a[i + 1] += A.a[i] / NN;
				A.a[i] %= NN;
			}
		}
		return A;
	}
};

Bigint F[5010];

void print(const Bigint& A)
{
	int i;
	for (i = MAX - 1 ; i >= 0; i--)
	{
		if (A.a[i]) break;
	}
	if (i < 0)
	{
		puts("0");
		return ;
	}
	printf("%d", A.a[i]);
	for (i--; i >= 0; i--)
		printf("%04d", A.a[i]);
	puts("");
	return ;
}

int main()
{
	int n;
	F[0] = 0;
	F[1] = 1;
	for (n = 2; n <= 5000; n++)
		F[n] = F[n - 1] + F[n - 2];
	while (scanf("%d", &n) != EOF)
	{
		printf("The Fibonacci number for %d is ", n);
		print(F[n]);
	}
}