/**
 *  @judge UVa
 *  @id 10038
 *  @tag 1.0, Ad-hoc
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#define MAX 3010
int jolly[MAX];

int main()
{
	int i, n, before, after;
	while (scanf("%d", &n) != EOF)
	{
		memset(jolly, 0, sizeof(jolly));
		scanf("%d", &after);
		for (i = 1; i < n; i++)
		{
			before = after;
			scanf("%d", &after);
			if (abs(before - after) < n)
				jolly[abs(before - after)]++;
		}
		for (i = 1; i < n; i++)
			if (jolly[i] != 1)
				break;
		if (i == n) puts("Jolly");
		else puts("Not jolly");
	}
}