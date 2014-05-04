#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int a[15], t, n, cnt;
	for (scanf("%d", &t), cnt = 1; cnt <= t; cnt++)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		printf("Case %d: %d\n", cnt, a[n / 2]);
	}
}