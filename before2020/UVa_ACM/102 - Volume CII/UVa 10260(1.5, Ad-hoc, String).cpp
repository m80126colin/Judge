/**
 *  @judge UVa
 *  @id 10260
 *  @tag 1.5, Ad hoc, String
 */
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
using namespace std;

#define MAX 30
#define ENMAX 7
string word[ENMAX] = {"AEIOUHWY", "BFPV", "CGJKQSXZ", "DT", "L", "MN", "R"};
char str[MAX];

int main()
{
	int i, j, len;
	while (gets(str))
	{
		len = strlen(str);
		for (i = 0; i < len; i++)
		{
			for (j = 0; j < ENMAX; j++)
			{
				if (word[j].find(str[i]) != string::npos)
				{
					str[i] = j + '0';
					break;
				}
			}
		}
		if (str[0] != '0') putchar(str[0]);
		for (i = 1; i < len; i++)
			if (str[i] != '0' && str[i] != str[i - 1])
				putchar(str[i]);
		puts("");
	}
}