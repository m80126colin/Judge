/**
 *  @judge NTHU
 *  @id 9053
 *  @tag Prime, BIT
 */
#include <stdio.h>
#include <string.h>
#include <iostream>
#define M 10010
using namespace std;

bool ox[M];
int p[M], pr;
int bit[M];

inline int lowbit(int t)
{
	return t & (-t);
}

inline int getsum(int t)
{
	int sum = 0;
	while (t > 0)
	{
		sum += bit[t];
		t -= lowbit(t);
	}
	return sum;
}

inline void insert(int t, int d)
{
	while (t < M)
	{
		bit[t] += d;
		t += lowbit(t);
	}
	return ;
}

inline void sieve()
{
	int i, j;
	ox[1] = 1;
	for (i = 2, pr = 0; i < M; i++)
	{
		if (!ox[i])
		{
			insert(i, 1);
			p[pr++] = i;
			for (j = 2; i * j < M; j++)
				ox[i * j] = 1;
		}
	}
	return ;
}

int main()
{
	int t, a, b;
	sieve();
	for (scanf("%d", &t); t; t--)
	{
		scanf("%d%d", &a, &b);
		printf("%d\n", getsum(b) - getsum(a - 1));
	}
}