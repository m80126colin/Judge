#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int g[101];

int getd(int &d)
{
	char ch;
	while (!isdigit(ch = getchar()));
	d = 0;
	do {
		d = d * 10 + ch - '0';
	} while (isdigit(ch = getchar()));
	return 1;
}

int main()
{
	bool ox;
	int n, i, j, tmp;
	while (getd(n), n)
	{
		ox = 0;
		memset(g, 0, sizeof(g));
		for (i = 0; i < n; i++)
		{
			getd(tmp);
			g[tmp]++;
		}
		for (i =0; i <= 100; i++)
			for (j = 0; j < g[i]; j++)
			{
				if (ox) putchar(' ');
				printf("%d", i);
				ox = 1;
			}
		puts("");
	}
}