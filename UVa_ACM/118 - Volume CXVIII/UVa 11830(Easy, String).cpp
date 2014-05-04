#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int i, flag;
	char n;
	string s;
	while (cin >> n >> s, (n != '0' || s != "0"))
	{
		flag = 1;
		for (i = 0; i < s.size(); i++)
		{
			if (s[i] != n && ((s[i] == '0' && (!flag)) || (s[i] != '0')))
			{
				putchar(s[i]);
				flag = 0;
			}
		}
		if (flag) putchar('0');
		puts("");
	}
}