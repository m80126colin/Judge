/**
 *  @judge NTUJ
 *  @id 1658
 *  @tag Simple, Prime
 */
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define PMAX 10010
#define SMAX 1000
bool ox[PMAX], ox2[PMAX];
int num[SMAX + 10], p[PMAX];

void pre()
{
	int i, j, x, y, ta = 1, pr = 0;
	ox[1] = ox2[1] = 1;
	for (i = 2; i < SMAX; i++)
	{
		if (!ox[i])
		{
			p[pr] = i;
			for (j = i; j < PMAX; j *= i)
			{
				ox2[j] = 1;
				for (x = 0; x < pr; x++)
				{
					for (y = p[x]; y * j < PMAX; y *= p[x])
						ox2[y * j] = 1;
				}
			}
			pr++;
			for (j = 2; j * i < PMAX; j++)
				ox[j * i] = 1;
		}
	}
	for (i; i < PMAX; i++)
	{
		if (!ox[i])
		{
			p[pr] = i;
			j = i;
			ox2[j] = 1;
			for (x = 0; x < pr; x++)
			{
				for (y = p[x]; (long long) y * j < PMAX; y *= p[x])
					ox2[y * j] = 1;
			}
			pr++;
		}
	}
	for (i = 30; i < PMAX && ta < SMAX + 10; i++)
	{
		if (!ox2[i])
		{
			num[ta] = i;
			ta++;
		}
	}
	return ;
}

int main()
{
	int t, n;
	pre();
	for (scanf("%d", &t); t; t--)
	{
		scanf("%d", &n);
		printf("%d\n", num[n]);
	}
}