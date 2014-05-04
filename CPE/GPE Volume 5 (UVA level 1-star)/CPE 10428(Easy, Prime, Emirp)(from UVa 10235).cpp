#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#define pMAX 1000000
#define pSQRT 1000
using namespace std;

bool p[pMAX];

inline void gen()
{
	int i, j;
	memset(p, 1, sizeof(p));
	p[1] = 0;
	for (i = 2; i < pSQRT; i++)
	{
		if (p[i])
		{
			for (j = 2; i * j < pMAX; j++)
				p[i * j] = 0;
		}
	}
	return;
}

int reverse(int x)
{
	int d = 0;
	do
	{
		d = d * 10 + x % 10;
		x /= 10;
	}
	while (x);
	return d;
}

int main()
{
	int n, m;
	gen();
	while (scanf("%d", &n) != EOF)
	{
		printf("%d is ", n);
		if (p[n]) {
			m = reverse(n);
			if (m != n && p[m]) puts("emirp.");
			else puts("prime.");
		}
		else puts("not prime.");
	}
}