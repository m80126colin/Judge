/**
 *  @judge UVa
 *  @id 10921
 *  @tag 1.5, Ad-hoc, String, Cellphone
 */
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;

#define MAX 50
string number[10] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};
char str[MAX];

int main()
{
	int i, j, len, pos;
	while (gets(str))
	{
		len = strlen(str);
		for (i = 0; i < len; i++)
		{
			for (j = 2; j < 10; j++)
			{
				if ((pos = number[j].find(str[i])) != string::npos)
				{
					str[i] = j + '0';
					break;
				}
			}
		}
		puts(str);
	}
}