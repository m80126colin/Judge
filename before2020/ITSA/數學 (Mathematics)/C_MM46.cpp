#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int a, b, c, d, n;
	char ch;
	for (scanf("%d", &n); n; n--)
	{
		cin.ignore(1);
		scanf("%c%d%d%d%d", &ch, &a, &b, &c, &d);
		if (ch == '+')
		{
			a += c;
			b += d;
		}
		else if (ch == '-')
		{
			a -= c;
			b -= d;
		}
		else
		{
			int tmpa, tmpb;
			tmpa = a * c - b * d;
			tmpb = a * d + c * b;
			a = tmpa;
			b = tmpb;
		}
		printf("%d %d\n", a, b);
	}
}