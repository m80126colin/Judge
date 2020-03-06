/**
 *  @judge UVa
 *  @id 12243
 *  @tag 1.0, Ad hoc, Count letter
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <iostream>
using namespace std;

#define MAX 1010
char str[MAX];

int main()
{
	int i, ans, flag, len;
	while (gets(str), str[0] != '*')
	{
		len = strlen(str);
		for (i = 0; i <len; i++)
			str[i] = tolower(str[i]);
		
		for (i = ans = flag = 1; i < len; i++)
		{
			if (str[i] >= 'a' && str[i] <= 'z')
			{
				if (!flag && str[i] != str[0]) ans = 0;
				flag = 1;
			}
			else flag = 0;
		}
		if (ans) puts("Y");
		else puts("N");
	}
}