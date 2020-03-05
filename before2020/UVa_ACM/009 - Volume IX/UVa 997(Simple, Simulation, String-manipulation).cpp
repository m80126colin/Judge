#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

char codification[110];
int n, num, symbol[110], diff[110];

void Extract()
{
	int i, depth, len = strlen(codification);
	for (i = depth = 0; i < len; i++)
	{
		if (codification[i] == '[')
		{
			depth++;
			num = max(depth, num);
		}
		else if (codification[i] == ']')
		{
			depth--;
		}
		else if (codification[i] == '+')
		{
			symbol[depth] = 1;
		}
		else if (codification[i] == '*')
		{
			symbol[depth] = 2;
		}
		else
		{
			int flag = 0;
			if (codification[i] == '-') flag = 1, i++;
			for (diff[depth] = 0; codification[i] >= '0' && codification[i] <= '9'; i++)
			{
				diff[depth] *= 10;
				diff[depth] += codification[i] - '0';
			}
			i--;
			if (flag) diff[depth] = -diff[depth];
		}
	}
	return ;
}

int main()
{
	int i, j;
	while (scanf("%s%d", codification, &n) != EOF)
	{
		memset(symbol, 0, sizeof(symbol));
		memset(diff, 0, sizeof(diff));
		Extract();
		for (j = 1; j < num; j++)
			if (symbol[j] == 2) diff[j] *= diff[j + 1];
		for (i = 0; i < n; i++)
		{
			if (i) putchar(' ');
			printf("%d", diff[1]);
			for (j = 1; j < num; j++)
				if (symbol[j] == 1) diff[j] += diff[j + 1];
			for (j = num - 1; j; j--)
				if (symbol[j] == 2) diff[j] *= diff[j + 1];
		}
		puts("");
	}
}