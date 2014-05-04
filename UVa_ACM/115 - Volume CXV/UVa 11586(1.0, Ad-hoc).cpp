#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int n, m, f;

void input()
{
	int i;
	char tmp[3], ch;
	n = m = f = 0;
	do
	{
		scanf("%s%c", tmp, &ch);
		for (i = 0; i < 2; i++)
			if (tmp[i] == 'M') m++;
			else f++;
		n++;
	} while (ch != '\n');
	return ;
}

int main()
{
	int t;
	for (scanf("%d", &t); t; t--)
	{
		input();
		if (n > 1 && m == f) puts("LOOP");
		else puts("NO LOOP");
	}
}