#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

#define PI (2.0 * acos(0.0))

int n, d, l;

int main()
{
	for (scanf("%d", &n); n; n--)
	{
		scanf("%d%d", &d, &l);
		printf("%.3lf\n", PI * sqrt((double) l * l - d * d) * l / 4.0);
	}
}