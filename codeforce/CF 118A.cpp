#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
using namespace std;

int main()
{
	char s[110], ch[7] = "aeiouy";
	while (scanf("%s", &s) != EOF)
	{
		int i, len = strlen(s);
		for (i = 0; i < len; i++)
		{
			s[i] = tolower(s[i]);
			if (strchr(ch, s[i]) == NULL)
				printf(".%c", s[i]);
		}
		puts("");
	}
}