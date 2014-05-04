#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;

long long S, D, d;

int main()
{
	while (scanf("%lld%lld", &S, &D) != EOF)
	{
		D--;
		d = 2 * S - 1;
		d = (-d + sqrt((double) d * d + 8 * D)) / 2.0;
		printf("%lld\n", S + d);
	}
}