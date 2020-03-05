#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;

int n, k;
int head, tail;

int main()
{
	int t, i, tmp;
	double s;
	for (scanf("%d", &t); t; t--)
	{
		scanf("%d%d", &n, &k);
		s = (double) log10((double) n) * k;
		s -= ((int) s);
		s = pow(10.0, s) * 100.0;
		head = (int) s;

		tmp = n % 1000;
		tail = 1;
		for (i = 1; i <= k; i <<= 1)
		{
			if (k & i)
			{
				tail *= tmp;
				tail %= 1000;
			}
			tmp *= tmp;
			tmp %= 1000;
		}
		printf("%d...%03d\n", head, tail);
	}
}