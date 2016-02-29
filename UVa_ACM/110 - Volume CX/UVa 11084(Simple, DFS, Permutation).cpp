#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

char s[15];
int d, len;

int Divid()
{
	long long tmp = 0;
	int i;
	for (i = 0; i < len; i++)
	{
		tmp *= 10;
		tmp += s[i] - '0';
	}
	return (tmp % d == 0);
}

int main()
{
	int t, cnt;
	for (scanf("%d", &t); t; t--)
	{
		scanf("%s%d", s, &d);
		len = strlen(s);
		cnt = 0;
		sort(s, s + len);
		do
		{
			if (Divid()) cnt++;
		} while (next_permutation(s, s + len));
		printf("%d\n", cnt);
	}
}