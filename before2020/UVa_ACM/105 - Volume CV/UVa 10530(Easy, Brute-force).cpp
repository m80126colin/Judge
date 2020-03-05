#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int d, i, a[11];
	string s;
	while (scanf("%d", &d), d)
	{
		memset(a, 0, sizeof(a));
		cin >> s;
		cin >> s;
		if (s == "high")
		{
			for (i = d; i <= 10; i++)
				a[i] = 1;
		}
		else if (s == "low")
		{
			for (i = d; i; i--)
				a[i] = 1;
		}
		while (s != "on")
		{
			cin >> d;
			cin >> s;
			cin >> s;
			if (s == "high")
			{
				for (i = d; i <= 10; i++)
					a[i] = 1;
			}
			else if (s == "low")
			{
				for (i = d; i; i--)
					a[i] = 1;
			}
			else break;
		}
		if (a[d]) puts("Stan is dishonest");
		else puts("Stan may be honest");
	}
}