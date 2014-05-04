#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int t, cnt, c, d;
	for (scanf("%d", &t), cnt = 1; cnt <= t; cnt++)
	{
		scanf("%d%d", &c, &d);
		printf("Case %d: %.2lf\n", cnt, c + d * 5.0 / 9.0);
	}
}