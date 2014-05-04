#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	char ch;
	int t, cnt, i, num;
	string s, tt;
	for (scanf("%d", &t), cnt = 1; cnt <= t; cnt++)
	{
		cin >> s;
		printf("Case %d: ", cnt);
		tt = "";
		for (i = 0; i < s.size(); i++)
		{
			if (isdigit(s[i]))
			{
				num = 0;
				do
				{
					num *= 10;
					num += s[i] - '0';
					i++;
				} while (i < s.size() && isdigit(s[i]));
				i--;
				while (num--) tt += ch;
			}
			else if (isalpha(s[i])) ch = s[i];
		}
		cout << tt << endl;
	}
}