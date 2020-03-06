/**
 *  @judge UVa
 *  @id 10773
 *  @tag Easy, Math
 */
#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

int main()
{
	int t, cnt, d, v, u;
	for (scanf("%d", &t), cnt = 1; cnt <= t; cnt++)
	{
		scanf("%d%d%d", &d, &v, &u);
		printf("Case %d: ", cnt);
		if (u <= v || u == 0 || v == 0) puts("can't determine");
		else printf("%.3lf\n", (double) d * (1.0 / sqrt((double) u * u - v * v) - 1.0 / u) );
	}
}