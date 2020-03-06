/**
 *  @judge UVa
 *  @id 914
 *  @tag 2.0, Number Theory, Prime sieve, Count frequency
 */
#include <cstdio>
#include <iostream>
using namespace std;

#define N 1000010
bool isprime[N];
int prime[N], pnum;
int ans[N], cnt[N], anum;

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

void sol(int a, int b)
{
	int i, j, df;
	anum = 0;
	for (i = 0; i < pnum - 1 && prime[i] < a; i++) ;
	for (; i < pnum - 1 && prime[i + 1] <= b; i++)
	{
		df = prime[i + 1] - prime[i];
		for (j = 0; j < anum; j++)
			if (ans[j] == df)
			{
				cnt[j]++;
				break;
			}
		if (j == anum)
		{
			ans[anum] = df;
			cnt[anum] = 1;
			anum++;
		}
	}
	for (i = j = 0; i < anum; i++)
		j = max(j, cnt[i]);
	for (i = df = 0; i < anum; i++)
		if (j == cnt[i])
			df++;
	if (df > 1 || anum == 0)
		puts("No jumping champion");
	else
	{
		for (i = 0; i < anum; i++)
			if (j == cnt[i])
				break;
		printf("The jumping champion is %d\n", ans[i]);
	}
}

int main()
{
	int t, L, U;
	sieve();
	for (scanf("%d", &t); t; t--)
	{
		scanf("%d%d", &L, &U);
		sol(L, U);
	}
}