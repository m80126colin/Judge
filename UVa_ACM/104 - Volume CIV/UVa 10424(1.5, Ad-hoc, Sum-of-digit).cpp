#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
using namespace std;

#define MAX 30
char s1[MAX], s2[MAX];

int SOD(int num)
{
	if (num < 10) return num;
	int sod;
	for (sod = 0; num; num /= 10)
		sod += num % 10;
	return SOD(sod);
}

int SOD(char *str)
{
	int i, sod, len = strlen(str);
	for (i = sod = 0; i < len; i++)
	{
		if (isalpha(str[i]))
		{
			if ('A' <= str[i] && str[i] <= 'Z') sod += str[i] - 'A' + 1;
			else sod += str[i] - 'a' + 1;
		}
	}
	return SOD(sod);
}

int main()
{
	int a, b;
	while (gets(s1) && gets(s2))
	{
		a = SOD(s1);
		b = SOD(s2);
		if (a > b) swap(a, b);
		printf("%.2lf %%\n", a * 100.0 / b);
	}
}