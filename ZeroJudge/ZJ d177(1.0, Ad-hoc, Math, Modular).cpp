#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

int main()
{
	int n, ans, i, len;
	char str[110];
	for (scanf("%d", &n); n; n--)
	{
		scanf("%s", str);
		len = strlen(str);
		for (i = ans = 0; i < len; i++)
		{
			ans *= 10;
			ans += str[i] - '0';
			ans %= 360;
		}
		printf("%d\n", ans);
	}
}