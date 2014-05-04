#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int t, n, m, x, i, j, b[50];
	vector<int> a;
	for (t = 1; scanf("%d%d", &n, &x) != EOF; t++)
	{
		for (i = 0; i < 20; i++)
			scanf("%d", &b[i]);
		a.clear();
		for (i = 1; i <= n; i++)
			a.push_back(i);
		m = a.size();
		for (i = 0; m > x && i < 20; i++)
		{
			m = a.size();
			for (j = b[i]; m > x && j <= a.size(); j += b[i])
			{
				a[j - 1] = 0;
				m--;
			}
			for (j = 0; j < a.size(); j++)
				if (a[j] == 0)
				{
					a.erase(a.begin() + j);
					j--;
				}
		}
		printf("Selection #%d\n", t);
		for (i = 0; i < a.size(); i++)
		{
			if (i) putchar(' ');
			printf("%d", a[i]);
		}
		puts("\n");
	}
}