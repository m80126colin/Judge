#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
using namespace std;

int t, a, b;

struct Bigint
{
#define MAXN 10000
#define M 50
	int a[M];
	Bigint() {
		memset(a, 0, sizeof(a));
	}
	Bigint(const int &b)
	{
		int i;
		memset(a, 0, sizeof(a));
		a[0] = b;
		for (i = 0; i < M - 1; i++)
		{
			if (a[i] / MAXN)
			{
				a[i + 1] += a[i] / MAXN;
				a[i] %= MAXN;
			}
			else break;
		}
	}
	Bigint& operator = (const int &b)
	{
		(*this) = Bigint(b);
		return (*this);
	}
	Bigint& operator += (const Bigint &b)
	{
		int i;
		for (i = 0; i < M; i++)
			a[i] += b.a[i];
		for (i = 0; i < M - 1; i++)
			if (a[i] / MAXN)
			{
				a[i + 1] += a[i] / MAXN;
				a[i] %= MAXN;
			}
		return (*this);
	}
	Bigint operator + (const Bigint &b)
	{
		Bigint c;
		c = (*this);
		c += b;
		return c;
	}
	Bigint operator * (const Bigint &b)
	{
		int i, j, x, y;
		for (x = M - 1; x >= 0 && a[x] == 0; x--);
		for (y = M - 1; y >= 0 && b.a[y] == 0; y--);
		if (x < 0 || y < 0)
			return Bigint(0);
		Bigint c;
		for (i = 0; i <= x; i++)
		{
			for (j = 0; j <= y; j++)
				c.a[i + j] += a[i] * b.a[j];
			for (j = 0; i + j < M - 1; j++)
			{
				if (c.a[i + j] / MAXN)
				{
					c.a[i + j + 1] += c.a[i + j] / MAXN;
					c.a[i + j] %= MAXN;
				}
			}
		}
		return c;
	}
	Bigint& operator *= (const Bigint &b)
	{
		(*this) = (*this) * b;
		return (*this);
	}
};

void print()
{
	int i, x = a / b;
	Bigint ans, term, tmp;
	tmp = term = 1;
	for (i = 0; i < b; i++)
		tmp *= Bigint(t);
	for (i = 0; i < x; i++)
	{
		ans += term;
		term *= tmp;
	}
	for (i = M - 1; i >= 0 && ans.a[i] == 0; i--);
	if (i < 0)
	{
		puts("0");
		return;
	}
	printf("%d", ans.a[i]);
	for (i--; i >= 0; i--)
		printf("%04d", ans.a[i]);
	puts("");
	return ;
}

int main()
{
	while (scanf("%d%d%d", &t, &a, &b) != EOF)
	{
		printf("(%d^%d-1)/(%d^%d-1) ", t, a, t, b);
		if (t == 1 || a % b != 0)
			puts("is not an integer with less than 100 digits.");
		else if (a == b)
			puts("1");
		else if (log10(pow((double) t, (double) a) - 1) - log10(pow((double) t, (double) b) - 1) < 99)
			print();
		else puts("is not an integer with less than 100 digits.");
	}
}