#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

int main()
{
	long long n, m;
	while (scanf("%lld", &n), n)
	{
		m = sqrt((double) n);
		if (m * m == n) puts("yes");
		else puts("no");
	}
}