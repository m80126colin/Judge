/**
 *  @judge UVa
 *  @id 272
 *  @tag 1.0, Ad-hoc
 */
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	char ch;
	int count = 0;
	while ((ch = getchar()) != EOF)
	{
		if (ch == '\"')
		{
			count++;
			if (count & 1)
			{
				putchar('`');
				putchar('`');
			}
			else 
			{
				putchar('\'');
				putchar('\'');
			}
		}
		else putchar(ch);
	}
}