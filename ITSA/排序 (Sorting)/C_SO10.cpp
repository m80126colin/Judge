#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int i, n, a[60];
	while (scanf("%d", &n) != EOF)
	{
		for (i = 0; i < n; i++) scanf("%d", &a[i]);
		sort(a, a+n);
		for (i = 0; i < n; i++)
			printf("%d ", a[i]);
		puts("");
	}
}