#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int t, a, b;
	while (scanf("%d%d%d", &t, &a, &b) != EOF)
	{
		switch (t)
		{
			case 1:
				a += b;
				break;
			case 2:
				a -= b;
				break;
			case 3:
				a *= b;
				break;
			case 4:
				a %= b;
				break;
			default:
				break;
		};
		printf("%d\n", a);
	}
}