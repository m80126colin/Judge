#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;



int main()
{
	int n, m, a[36], p[9], i, j, s, ctr;
	srand(time(NULL));
	freopen("q10202.txt", "w", stdout);
	while (cin >> n)
	{
		printf("%d\n", n);
		m = n * (n - 1) / 2;
		for (i = 0; i < n; i++) scanf("%d", &p[i]);
		s = 0;
		for (i = 0; i < n; i++)
		{
			for (j = i + 1; j < n; j++)
			{
				a[s++] = p[i] + p[j];
			}
		}
		for (i = 0; i < s; i++)
		{
			if (i) putchar(' ');
			printf("%d", a[i]);
		}
		puts("");
	}
	for (ctr = 0; ctr < 70000; ctr++)
	{
		n = rand() % 6 + 3;
		m = n * (n - 1) / 2;
		s = rand() % 9;
		printf("%d\n", n);
		if (s)
		{
			for (i = 0; i < n; i++) p[i] = ((long long) ((long long) rand() * rand()) % 250000) - (rand() % 50000);
			s = 0;
			for (i = 0; i < n; i++)
			{
				for (j = i + 1; j < n; j++)
				{
					a[s++] = p[i] + p[j];
				}
			}
		}
		else
		{
			for (i = 0; i < m; i++) a[i] = ((long long) ((long long) rand() * rand()) % 500000) - (rand() % 100000);
		}
		for (i = 0; i < m; i++)
		{
			if (i) putchar(' ');
			printf("%d", a[i]);
		}
		puts("");
	}
}