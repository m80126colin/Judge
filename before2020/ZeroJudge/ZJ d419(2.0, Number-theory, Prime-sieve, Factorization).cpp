/**
 *  @judge ZeroJudge
 *  @id d419
 *  @source UVa 884
 * 
 *  @tag 2.0, Number Theory, Prime sieve, Factorization
 */
#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

#define N 1000010
bool isprime[N];
int ans[N];
int prime[N], pnum;

void sieve()
{
	int i, j, sqn = sqrt((double) N);
	pnum = 0;
	for (i = 0; i < N; i++)
		isprime[i] = 1;
	isprime[0] = isprime[1] = 0;
	for (i = 2; i <= sqn; i++)
	{
		if (isprime[i]) prime[pnum++] = i;
		for (j = i * i; j < N; j += i)
			isprime[j] = 0;
	}
}

void sol()
{
	int i, j, res, m;
	for (i = 2; i < N; i++)
	{
		res = 0;
		for (m = i, j = 0; isprime[m] == 0 && j < pnum && prime[j] <= m; j++)
			while (m % prime[j] == 0)
			{
				res++;
				m /= prime[j];
			}
		if (m > 1) res++;
		ans[i] = ans[i - 1] + res;
	}
}

int main()
{
	int n;
	sieve();
	sol();
	while (scanf("%d", &n) != EOF)
		printf("%d\n", ans[n]);
}