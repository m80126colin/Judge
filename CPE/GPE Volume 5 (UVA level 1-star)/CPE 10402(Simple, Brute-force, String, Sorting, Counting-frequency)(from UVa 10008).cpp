#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <iostream>
#include <algorithm>
using namespace std;

struct alp
{
	char cc;
	int num;
}a[26];

bool cmp(alp x, alp y)
{
	return x.num > y.num || (x.num == y.num && x.cc < y.cc);
}

int main()
{
	int t, i;
	char ch;
	while (cin >> t)
	{
		cin.ignore(1);
		memset(a, 0, sizeof(a));
		for (i = 0; i < 26; i++) a[i].cc = 'A' + i;
		while (t && (ch = getchar()))
		{
			if (ch == '\n')
			{
				t--;
				continue;
			}
			if (isalpha(ch))
			{
				if (ch >= 'a' && ch <= 'z') ch -= 'a';
				else ch -= 'A';
				a[ch].num++;
			}
		}
		sort(a, a+26, cmp);
		for (i = 0; i < 26; i++)
		{
			if (a[i].num) printf("%c %d\n", a[i].cc, a[i].num);
		}
	}
}