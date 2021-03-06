/**
 *  @judge ZeroJudge
 *  @id d438
 *  @source UVa 10533
 * 
 *  @tag 2.0, Number Theory, Prime sieve, Digit sum, Prefix Sum
 */
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define N 1000010
bool ox[N];
int pr[N], pn, ans[N];

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

int sum(int n)
{
	int res = 0;
	while (n)
	{
		res += n % 10;
		n /= 10;
	}
	return res;
}

void sol()
{
	for (int i = 2; i < N; i++)
	{
		ans[i] = ans[i - 1];
		if (ox[i] && ox[sum(i)])
			ans[i]++;
	}
	return;
}

int main()
{
	int t, a, b;
	sieve();
	sol();
	for (scanf("%d", &t); t; t--)
	{
		scanf("%d%d", &a, &b);
		printf("%d\n", ans[b] - ans[a - 1]);
	}
}