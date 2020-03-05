#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

string s[1000010];

int main()
{
	int n, i, cnt, num;
	for (scanf("%d", &n), getline(cin, s[0]), getline(cin, s[0]); n; n--)
	{
		for (cnt = 0; getline(cin, s[cnt]); cnt++)
			if (s[cnt] == "") break;
		sort(s, s + cnt);
		for (i = num = 1; i < cnt; i++)
		{
			if (s[i] != s[i - 1])
			{
				cout << s[i - 1];
				printf(" %.4lf\n", (double) num * 100.0 / cnt);
				num = 0;
			}
			num++;
		}
		cout << s[cnt - 1];
		printf(" %.4lf\n", (double) num * 100 / cnt);
		if (n > 1) puts("");
	}
}