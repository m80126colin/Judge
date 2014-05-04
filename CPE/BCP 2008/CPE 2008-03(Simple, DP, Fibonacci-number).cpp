#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

long long f[50];

int main()
{
	int i, ctr;
	f[0] = 0, f[1] = 1;
	for (i = 2; i < 50; i++)
	{
		f[i] = f[i-1] + f[i-2];
	}
	for (ctr = 1; cin >> i; ctr++)
	{
		printf("case %d:\n", ctr);
		if (i >= 48) puts("overflow");
		else printf("%lld\n", f[i]);
		puts("");
	}
}