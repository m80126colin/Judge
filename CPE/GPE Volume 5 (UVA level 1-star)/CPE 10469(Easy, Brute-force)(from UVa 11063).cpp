#include <stdio.h>
#include <iostream>
#include <string.h>
#define N 110
#define M 20010
using namespace std;

bool ox[M];
int b2[N], n;

bool isox()
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		if (b2[i] >= b2[i + 1]) return 0;
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (ox[b2[i] + b2[j]]) return 0;
			ox[b2[i] + b2[j]] = 1;
		}
	}
	return 1;
}

int main()
{
	int i, ctr;
	for (ctr = 1; scanf("%d", &n) != EOF; ctr++)
	{
		for (i = 0; i < n; i++) scanf("%d", &b2[i]);
		memset(ox, 0, sizeof(ox));
		printf("Case #%d: ", ctr);
		if (isox()) puts("It is a B2-Sequence.");
		else puts("It is not a B2-Sequence.");
		puts("");
	}
}