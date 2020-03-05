#include <stdio.h>
#include <iostream>
using namespace std;

int s, x, y, dx, dy, cnt;

int in_white()
{
	if (x % s == 0 || y % s == 0)
		return 0;
	return ((x / s) & 1) ^ ((y / s) & 1);
}

int check()
{
	for (cnt = 0; cnt < 10000; cnt++)
	{
		if (in_white()) return 1;
		x += dx;
		y += dy;
	}
	return 0;
}

int main()
{
	while (scanf("%d%d%d%d%d", &s, &x, &y, &dx, &dy), (s || x || y || dx || dy))
	{
		if (check()) printf("After %d jumps the flea lands at (%d, %d).\n", cnt, x, y);
		else puts("The flea cannot escape from black squares.");
	}
}