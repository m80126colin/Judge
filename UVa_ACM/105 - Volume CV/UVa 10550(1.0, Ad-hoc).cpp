#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int a, b, c, d;
	while (scanf("%d%d%d%d", &a, &b, &c, &d), (a || b || c || d))
	{
		d = (40 + c - d) % 40;
		c = (40 + c - b) % 40;
		b = (40 + a - b) % 40;
		printf("%d\n", 720 + 360 + (b + c + d) * 9);
	}
}