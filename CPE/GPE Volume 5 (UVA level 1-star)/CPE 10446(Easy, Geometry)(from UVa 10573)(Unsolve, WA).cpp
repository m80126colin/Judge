#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

int main()
{
	int r1, r2, n;
	for (scanf("%d", &n); n; n--)
	{
		scanf("%d", &r1);
		if (cin.peek() != '\n')
		{
			scanf("%d", &r2);
			if (r1 < 0 || r2 < 0) puts("Impossible");
			else printf("%.4lf\n", (double) 4.0 * r1 * r2 * acos(0.0));
		}
		else if (r1 < 0) puts("Impossible");
		else printf("%.4lf\n", (double) r1 * r1 * acos(0.0) / 4.0);
	}
}