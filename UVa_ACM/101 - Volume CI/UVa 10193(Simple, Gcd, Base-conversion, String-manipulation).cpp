#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

char str[110];

void convert(long long &d)
{
	d = 0;
	int i, len = strlen(str);
	for (i = 0; i < len; i++)
	{
		d <<= 1;
		d += str[i] - '0';
	}
	return ;
}

long long gcd(long long a, long long b)
{
	if (b) return gcd(b, a % b);
	return a;
}

int main()
{
	int t, cnt;
	long long a, b;
	for (scanf("%d", &t), cnt = 1; cnt <= t; cnt++)
	{
		scanf("%s", str);
		convert(a);
		scanf("%s", str);
		convert(b);
		printf("Pair #%d: ", cnt);
		if (gcd(a, b) > 1) puts("All you need is love!");
		else puts("Love is not all you need!");
	}
}