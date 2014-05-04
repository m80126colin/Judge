#include <cstdio>
#include <iostream>
using namespace std;

#define N 65536
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
	int i, flag = 0;
	printf("%d =", n);
	if (n < 0)
	{
		flag = 1;
		n = -n;
		printf(" -1");
	}
	for (i = 0; i < pnum && n > 1; i++)
	{
		while (n % prime[i] == 0)
		{
			if (flag) printf(" x");
			printf(" %d", prime[i]);
			n /= prime[i];
			flag = 1;
		}
	}
	if (n > 1)
	{
		if (flag) printf(" x");
		printf(" %d", n);
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