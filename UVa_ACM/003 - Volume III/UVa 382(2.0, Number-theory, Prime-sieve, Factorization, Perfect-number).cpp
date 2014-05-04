#include <cstdio>
#include <iostream>
using namespace std;

#define N 60010
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
	int i, m = n;
	printf("%5d  ", n);
	int tmp, cnt, res = 1;
	for (i = 0; i < pnum && n > 1; i++)
	{
		if (isprime[n])
		{
			res *= (1 + n);
			n /= n;
		}
		if (n % prime[i] == 0)
		{
			tmp = cnt = 1;
			while (n % prime[i] == 0)
			{
				cnt *= prime[i];
				tmp += cnt;
				n /= prime[i];
			}
			res *= tmp;
		}
	}
	res -= m;
	if (res > m) puts("ABUNDANT");
	else if (res == m) puts("PERFECT");
	else puts("DEFICIENT");
}

int main()
{
	int n;
	sieve();
	puts("PERFECTION OUTPUT");
	while (scanf("%d", &n), n)
		sol(n);
	puts("END OF OUTPUT");
}