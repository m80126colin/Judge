#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	long long n, t, cnt, L, x, y;
	for (scanf("%lld", &t), cnt = 1; cnt <= t; cnt++)
	{
		scanf("%lld", &n);
		n--;
		L = sqrt((double) n);
		n = n + 1 - L * L;
		L++;
		x = L;
		y = n;
		if (n > L)
		{
			y = L;
			x = L + L - n;
		}
		if ((L & 1) == 0) swap(x, y);
		printf("Case %lld: %lld %lld\n", cnt, x, y);
	}
}