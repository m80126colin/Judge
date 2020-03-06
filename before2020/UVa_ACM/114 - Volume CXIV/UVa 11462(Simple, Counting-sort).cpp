/**
 *  @judge UVa
 *  @id 11462
 *  @tag Simple, Counting sort
 */
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

int age[110];

int main()
{
	int n, i, tmp, ox;
	while (scanf("%d", &n), n)
	{
		memset(age, 0, sizeof(age));
		for (i = 0; i < n; i++)
		{
			scanf("%d", &tmp);
			age[tmp]++;
		}
		for (i = ox = 0; i < 110; i++)
		{
			while (age[i]--)
			{
				if (ox) putchar(' ');
				printf("%d", i);
				ox = 1;
			}
		}
		puts("");
	}
}