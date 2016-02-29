#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int t;
	long long n;
	for (scanf("%d", &t); t; t--)
	{
		scanf("%lld", &n);
		printf("%lld\n", (n = (double) (-1.0 + sqrt(1.0 + 8.0 * n)) / 2.0));
	}
}