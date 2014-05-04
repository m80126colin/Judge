#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

long long myabs(long long x)
{
	if (x < 0) return -x;
	return x;
}

int main()
{
	long long a, b;
	while (scanf("%lld%lld", &a, &b) != EOF)
	{
		printf("%lld\n", myabs(a-b));
	}
}