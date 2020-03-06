/**
 *  @judge TIOJ
 *  @id 1661
 *  @tag Easy, Straight forward
 */
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int n, q;
vector <int> a;

int main()
{
	int i, j;
	while (scanf("%d", &n) != EOF)
	{
		a.clear();
		for (i = 0; i < n; i++)
			scanf("%d", &j), a.push_back(j);
		scanf("%d", &q);
		while (q--)
		{
			scanf("%d%d", &i, &j);
			swap(a[i], a[j]);
		}
		for (i = 0; i < n; i++)
		{
			if (i) putchar(' ');
			printf("%d", a[i]);
		}
		puts("");
	}
}