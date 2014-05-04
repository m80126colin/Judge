#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

char c[50];

int main()
{
	int t, len;
	for (scanf("%d", &t); t; t--)
	{
		scanf("%s", c);
		len = strlen(c);
		sort(c, c + len);
		do
		{
			puts(c);
		} while(next_permutation(c, c + len));
		puts("");
	}
}