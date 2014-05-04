#include <stdio.h>
#include <iostream>
using namespace std;

#define PMAX 10000
#define SMAX 100
bool ox[PMAX];
int p[PMAX], sum[PMAX], pr;

void sieve()
{
	int i, j;
	memset(ox, 1, sizeof(ox));
	pr = 0;
	ox[1] = 0;
	for (i = 2; i < SMAX; i++)
	{
		if (ox[i])
		{
			p[pr++] = i;
			for (j = i + i; j < PMAX; j += i)
				ox[j] = 0;
		}
	}
	for (; i < PMAX; i++)
		if (ox[i]) p[pr++] = i;
	return ;
}

int main()
{
	int n, i;
	sieve();
	sum[0] = p[0];
	for (i = 1; i < pr; i++)
		sum[i] = sum[i - 1] + p[i];
	while (scanf("%d", &n) != EOF)
	{
		for (i = 0; i < n && i < pr; i++)
			printf("%d,", p[i]);
		puts("");
		printf("%d\n", sum[n - 1]);
	}
}