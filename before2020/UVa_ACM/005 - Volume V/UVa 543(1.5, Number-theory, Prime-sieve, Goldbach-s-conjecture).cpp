/**
 *  @judge UVa
 *  @id 543
 *  @tag 1.5, Number Theory, Prime sieve, Goldbach s conjecture
 */
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define N 1000010
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

void sol(int n)
{
	int i;
	for (i = 0; i < pn && pr[i] <= n - pr[i]; i++)
		if (ox[n - pr[i]])
		{
			printf("%d = %d + %d\n", n, pr[i], n - pr[i]);
			return ;
		}
	puts("Goldbach's conjecture is wrong.");
	return ;
}

int main()
{
	int n;
	sieve();
	while (scanf("%d", &n), n)
		sol(n);
}