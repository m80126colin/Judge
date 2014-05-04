#include <stdio.h>
#include <iostream>
using namespace std;

int DP[20], pre;

int main()
{
	int n;
	pre = 0;
	DP[0] = 1;
	for (n = 1; n <= 15; n++)
	{
		DP[n] += 3 * DP[n - 1] + 2 * pre;
		pre += DP[n - 1];
	}
	while (scanf("%d", &n), n != -1)
	{
		if (n & 1) puts("0");
		else printf("%d\n", DP[n >> 1]);
	}
}