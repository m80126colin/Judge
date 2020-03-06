/**
 *  @judge CPE
 *  @id 10548
 *  @tag Big number, Binary operation
 */
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
using namespace std;

char digit[10010];

int input()
{
	int i = 0;
	char ch;
	while ((ch = getchar()) != '#')
	{
		if (ch == EOF) return EOF;
		if (ch >= '0' && ch <= '1')
		{
			digit[i] = ch;
			i++;
		}
	}
	digit[i] = '\0';
	return i;
}

int DivDigit()
{
	int len = strlen(digit), i, j;
	for (i = 0; (len - i) >= 17; i++)
		if (digit[i] == '1')
			for (j = 0; j < 17; j++)
				digit[i + j] = (digit[i + j] == '1')?'0':'1';
	for (i = 0; i < len && digit[i] != '1'; i++);
	for (j = 0; i < len; i++, j++)
		digit[j] = digit[i];
	digit[j] = '\0';
	if (strlen(digit)) return 1;
	return 0;
}

int main()
{
	while (input() != EOF)
	{
		if (DivDigit())
			puts("NO");
		else puts("YES");
	}
}