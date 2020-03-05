#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

#define MAX 10000

int main()
{
	int n, date[MAX];
	int y, a, b, i, t;
	for (t = 1; scanf("%d", &n), n; t++)
	{
		memset(date, 0, sizeof(date));
		for (i = 0; i < n; i++)
		{
			scanf("%d%d%d", &y, &a, &b);
			for (b -= a; y < MAX; y += b)
				date[y]++;
		}
		printf("Case #%d:\n", t);
		for (i = 0; i < MAX; i++)
			if (date[i] == n)
			{
				printf("The actual year is %d.\n", i);
				break;
			}
		if (i == MAX) puts("Unknown bugs detected.");
		puts("");
	}
}