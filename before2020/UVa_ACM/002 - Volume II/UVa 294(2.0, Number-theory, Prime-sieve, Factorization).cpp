/**
 *  @judge UVa
 *  @id 294
 *  @tag 2.0, Number theory, Prime sieve, Factorization
 */
#include <cstdio>
#include <iostream>
using namespace std;

#define N 100010
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

int count(int n)
{
	int i, tmp, res = 1;
	for (i = 0; i < pnum && prime[i] <= n && n > 1; i++)
	{
		for (tmp = 1; n % prime[i] == 0; tmp++)
			n /= prime[i];
		res *= tmp;
	}
	return res;
}

void sol(int L, int U)
{
	int i, ans, cnt, tmp;
	ans = L;
	cnt = count(L);
	for (i = L + 1; i <= U; i++)
	{
		tmp = count(i);
		if (tmp > cnt)
		{
			ans = i;
			cnt = tmp;
		}
	}
	printf("Between %d and %d, %d has a maximum of %d divisors.\n", L, U, ans, cnt);
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