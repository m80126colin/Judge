#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int t, n, k, p, cnt;
	for (scanf("%d", &t), cnt = 1; cnt <= t; cnt++)
	{
		scanf("%d%d%d", &n, &k, &p);
		printf("Case %d: %d\n", cnt, (k + p - 1) % n + 1);
	}
}