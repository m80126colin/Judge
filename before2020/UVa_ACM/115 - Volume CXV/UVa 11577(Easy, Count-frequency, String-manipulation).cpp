/**
 *  @judge UVa
 *  @id 11577
 *  @tag Easy, Count frequency, String manipulation
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <iostream>
using namespace std;

int ch[26], mx;
char s[210];

int main()
{
	int t, i, len;
	for (scanf("%d", &t), cin.ignore(1); t; t--)
	{
		fgets(s, 209, stdin);
		memset(ch, 0, sizeof(ch));
		len = strlen(s);
		for (i = mx = 0; i < len; i++)
			if (isalpha(s[i]))
			{
				ch[tolower(s[i]) - 'a']++;
				mx = max(mx, ch[tolower(s[i]) - 'a']);
			}
		for (i = 0; i < 26; i++)
			if (ch[i] == mx) putchar(i + 'a');
		puts("");
	}
}