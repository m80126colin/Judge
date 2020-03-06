/**
 *  @judge NTUJ
 *  @id 1660
 *  @tag Easy, Loop, String
 */
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

int main()
{
	int t, i, flag;
	char str[110];
	for (scanf("%d", &t);t; t--)
	{
		scanf("%s", str);
		for (i = flag = 0; i < strlen(str); i++)
			if (str[i] == 'D')
			{
				flag = 1;
				break;
			}
		if (flag) puts("You shall not pass!");
		else puts("Possible");
	}
}