#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	while (scanf("%d%d%d", &a, &b, &c), (a || b || c))
	{
		if (a > b) swap(a, b);
		if (b > c) swap(b, c);
		if (a > b) swap(a, b);
		if (a > 0 && b > 0 && c > 0 && c * c - b * b == a * a) puts("right");
		else puts("wrong");
	}
}