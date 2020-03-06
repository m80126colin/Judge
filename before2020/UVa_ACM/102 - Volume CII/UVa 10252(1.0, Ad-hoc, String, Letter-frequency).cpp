/**
 *  @judge UVa
 *  @id 10252
 *  @tag 1.0, Ad hoc, String, Letter frequency
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#define MAX 1010
#define WMAX 26
char a[MAX], b[MAX];
int wa[WMAX], wb[WMAX];

void convert(char *str, int *fre)
{
	int i, len = strlen(str);
	for (i = 0; i < len; i++)
		fre[str[i] - 'a']++;
	return ;
}

int main()
{
	int i, j;
	while (gets(a) && gets(b))
	{
		memset(wa, 0, sizeof(wa));
		convert(a, wa);
		memset(wb, 0, sizeof(wb));
		convert(b, wb);
		for (i = 0; i < WMAX; i++)
			for (j = 0; j < min(wa[i], wb[i]); j++)
				putchar(i + 'a');
		puts("");
	}
}