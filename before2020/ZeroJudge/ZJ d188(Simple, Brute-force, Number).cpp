#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

#define SQU(x) ((x) * (x))
#define MAX 50010
int ox[MAX];

void pre()
{
	int i, j, k;
	for (i = 0; SQU(i) < MAX; i++)
		for (j = i; SQU(i) + SQU(j) < MAX; j++)
			for (k = j; SQU(i) + SQU(j) + SQU(k) < MAX; k++)
				ox[SQU(i) + SQU(j) + SQU(k)] = 1;
	return ;
}

void sol(int x)
{
	int i, j, k;
	for (i = 0; SQU(i) <= x; i++)
		for (j = i; SQU(i) + SQU(j) <= x; j++)
			for (k = j; SQU(i) + SQU(j) + SQU(k) <= x; k++)
				if (SQU(i) + SQU(j) + SQU(k) == x)
				{
					printf("%d %d %d\n", i, j, k);
					return ;
				}
	return ;
}

int main()
{
	int n, k;
	memset(ox, 0, sizeof(ox));
	pre();
	for (scanf("%d", &n); n; n--)
	{
		scanf("%d", &k);
		if (ox[k]) sol(k);
		else puts("-1");
	}
}