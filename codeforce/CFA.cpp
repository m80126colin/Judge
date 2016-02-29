#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int n;
string s;

inline int islucky()
{
	int i;
	for (i = 0; i < n; i++)
		if (s[i] != '4' && s[i] != '7')
			return 0;
	return 1;
}

inline int isticket()
{
	int i, m = n / 2, a, b;
	a = b = 0;
	for (i = 0; i < m; i++)
	{
		a += s[i];
		b += s[i + m];
	}
	return a == b;
}

int main()
{
	while (scanf("%d", &n) != EOF)
	{
		cin >> s;
		if ( islucky() )
		{
			if ( isticket() ) puts("YES");
			else puts("NO");
		}
		else puts("NO");
	}
}