/**
 *  @judge TIOJ
 *  @id 1662
 *  @tag Easy, String manipulation, I O
 */
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	char ch;
	while ((ch = getchar()) != EOF)
	{
		if (ch >= 'A' && ch <= 'Z')
			putchar(ch - 'A' + 'a');
		else if (ch >= 'a' && ch <= 'z')
			putchar(ch - 'a' + 'A');
		else if (ch == '\n')
			puts("");
		else putchar(' ');
	}
}