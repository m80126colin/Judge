#include <stdio.h>
#include <iostream>
#define MAX 1010
using namespace std;

int n, c[MAX], s, d1, d2;

int main()
{
	int i, ox;
	double d;
	while (scanf("%d", &n) , n)
	{
		for (i = s = 0; i < n; i++)
		{
			scanf("%lf", &d);
			d *= 100;
			c[i] = d + 0.00001;
			s += c[i];
		}
		ox = s % n;
		s /= n;
		for (i = d1 = d2 = 0; i < n; i++)
		{
			if (c[i] > s)
			{
				d1 += c[i] - s;
				if (ox) d1--, ox--;
			}
		}
		printf("$%d.%02d\n", d1/100, d1%100);
	}
}