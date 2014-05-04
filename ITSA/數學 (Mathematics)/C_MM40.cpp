#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int n, i, ans;
	while (scanf("%d", &n) != EOF)
	{
		ans = n * (n + 1) / 2;
		for (i = 1; i <= n; i++)
		{
			if (i > 1) printf("+ ");
			printf("%d ", i);
		}
		printf("= %d\n", ans);
	}
}