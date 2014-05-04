#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int a, b, c;
char ch, ch2, str[110];

int input()
{
	if (gets(str) == NULL)
		return EOF;
	if (str[strlen(str) - 1] == '?')
	{
		str[strlen(str) - 1] == '\0';
		strcat(str, "-1000");
	}
	sscanf(str, "%d%c%d%c%d", &a, &ch, &b, &ch2, &c);
	return 0;
}

int main()
{
	int ans = 0;
	while (input() != EOF)
	{
		if (ch == '+' && a + b == c) ans++;
		else if (ch == '-' && a - b == c) ans++;
	}
	printf("%d\n", ans);
}