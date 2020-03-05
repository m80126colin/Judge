#include <iostream>
#include <map>
#include <stdio.h>
using namespace std;

int main()
{
	char ch;
	int n, m, a;
	while (scanf("%d", &n) != EOF)
	{
		if ((ch = getchar()) != '\n')
		{
			a = 0;
			scanf("%d", &m);
			m -= ((2 + (m & 3)) % 4);
			n += ((6 - (n & 3)) % 4);
			a = (m - n) / 4 + 1;
			printf("%d\n", a);
		}
		else
		{
			if (n & 1) printf("%d %d\n", (n - 1) / 2 + 1, (n - 1) / 2);
			else if (n & 3) puts("Bachelor Number.");
			else
			{
				n /= 4;
				printf("%d %d\n", n + 1, n - 1);
			}
		}
	}
}