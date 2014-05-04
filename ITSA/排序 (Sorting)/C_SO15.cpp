#include <stdio.h>
#include <iostream>
using namespace std;

int s, a[4];

int input()
{
	int i, j;
	for (i = 0; i < 4; i++)
	{
		if (scanf("%d", &a[i]) == EOF)
			return 0;
	}
	s = 1;
	for (i = 0; i < 4; i++)
		for (j = i + 1; j < 4; j++)
			if (a[i] > a[j]) s++;
	return 1;
}

int main()
{
	while (input())
	{
		printf("%d\n", s & 1);
	}
}