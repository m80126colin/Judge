#include <stdio.h>
#include <iostream>
using namespace std;

int x, y, g;

int extgcd(int a, int b)
{
	if (!b)
	{
		x = 1;
		y = 0;
		return a;
	}
	int t, tmp = extgcd(b, a % b);
	t = x;
	x = y;
	y = t - (a / b) * x;
	return tmp;
}

int main()
{
	int a, b;
	while (scanf("%d%d", &a, &b) != EOF)
	{
		g = extgcd(a, b);
		printf("%d %d %d\n", x, y, g);
	}
}