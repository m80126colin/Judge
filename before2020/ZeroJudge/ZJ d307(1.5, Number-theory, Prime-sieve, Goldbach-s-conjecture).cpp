/**
 *  @judge ZeroJudge
 *  @id d307
 *  @source UVa 686
 * 
 *  @tag 1.5, Number Theory, Prime sieve, Goldbach s conjecture
 */
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define N 65536
bool ox[N];
int pr[N], pn;

void sieve()
{
	int i, j;
	memset(ox, 1, sizeof(ox));
	ox[0] = ox[1] = 0;
	for (i = 2; i < N; i++)
	{
		if (ox[i]) pr[pn++] = i;
		for (j = 0; j < pn && i * pr[j] < N; j++)
			ox[i * pr[j]] = 0;
	}
}

int sol(int n)
{
	int i, res = 0;
	for (i = 0; i < pn && pr[i] <= n - pr[i]; i++)
		if (ox[n - pr[i]])
			res++;
	return res;
}

int main()
{
	int n;
	sieve();
	while (scanf("%d", &n), n)
		printf("%d\n", sol(n));
}