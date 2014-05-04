#include <cstdio>
#include <iostream>
using namespace std;

#define N 110
bool isprime[N];
int prime[N], pnum;

void sieve()
{
	pnum = 0;
	for (int i = 0; i < N; i++)
		isprime[i] = 1;
	isprime[0] = isprime[1] = 0;
	for (int i = 2; i < N; i++)
	{
		if (isprime[i]) prime[pnum++] = i;
		for (int j = 0; j < pnum && i * prime[j] < N; j++)
			isprime[i * prime[j]] = 0;
	}
}

void sol(int n)
{
	int i, j, m;
	printf("%3d! =", n);
	for (i = 0; i < pnum && prime[i] <= n; i++)
	{
		if (i && i % 15 == 0)
			printf("\n      ");
		for (j = 0, m = n / prime[i]; m; m /= prime[i])
			j += m;
		printf("%3d", j);
	}
	puts("");
}

int main()
{
	int n;
	sieve();
	while (scanf("%d", &n), n)
		sol(n);
}