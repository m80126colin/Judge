#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int t, cnt;
	int a, b ,c;
	for (scanf("%d", &t), cnt = 1; cnt <= t; cnt++)
	{
		scanf("%d%d%d", &a, &b, &c);
		if (a < b) swap(a, b);
		if (b < c) swap(b, c);
		if (a < b) swap(a, b);
		printf("Case %d: ", cnt);
		if (a - b >= c) puts("Invalid");
		else if (a == b && b == c) puts("Equilateral");
		else if (a == b || b == c) puts("Isosceles");
		else puts("Scalene");
	}
}