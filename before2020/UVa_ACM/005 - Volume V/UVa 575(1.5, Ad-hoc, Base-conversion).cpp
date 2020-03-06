/**
 *  @judge UVa
 *  @id 575
 *  @tag 1.5, Ad-hoc, Number Base Conversion
 */
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

#define MAX 110

inline long long convert(char *str)
{
	int i, len = strlen(str);
	long long ans, d;
	ans = d = 0;
	for (i = 0; i < len; i++)
	{
		ans <<= 1;
		ans += (str[i] - '0');
		d += (str[i] - '0');
	}
	ans <<= 1;
	return ans - d;
}

int main()
{
	long long ans;
	char s[MAX];
	while (scanf("%s", &s) != EOF)
	{
		if (ans = convert(s)) printf("%lld\n", ans);
		else break;
	}
}