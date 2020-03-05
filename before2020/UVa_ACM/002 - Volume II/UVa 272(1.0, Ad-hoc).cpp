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