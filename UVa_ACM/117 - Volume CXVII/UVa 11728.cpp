#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
#define MAX 1010
using namespace std;

int ox[MAX];

int sf(int x)
{
	int i, s = 1, d, k;
	for (i = 2; i <= x; i++)
	{
		k = i;
		for (d = 1; !(x % i); x /= i, k *= i) d += k;
		s *= d;
	}
	return s;
}

int main()
{
	int ctr, i, n;
	memset(ox, 255, sizeof(ox));
	for (i = 1; i < 1000; i++)
	{
		n = sf(i);
		if (n <= 1000) ox[n] = i;
	}
	for (ctr = 1; cin >> n, n; ctr++)
	{
		printf("Case %d: %d\n", ctr, ox[n]);
	}
}