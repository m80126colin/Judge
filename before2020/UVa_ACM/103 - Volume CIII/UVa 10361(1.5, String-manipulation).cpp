/**
 *  @judge UVa
 *  @id 10361
 *  @tag 1.5, String Manipulation
 */
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main()
{
	int i, j, len, n;
	char s1[110], s2[110], *s[6];
	for (scanf("%d", &n), cin.ignore(); n; n--)
	{
		gets(s1);
		gets(s2);
		s[1] = s1;
		len = strlen(s1);
		for (i = 0, j = 1; i < len; i++)
		{
			if (s1[i] == '<' || s1[i] == '>')
			{
				s1[i] = '\0';
				s[j + 1] = s1 + (i + 1);
				j++;
			}
		}
		len = strlen(s2);
		for (i = 0; i < len; i++)
			if (s2[i] == '.')
				s2[i] = '\0';
		printf("%s%s%s%s%s\n", s[1], s[2], s[3], s[4], s[5]);
		printf("%s%s%s%s%s\n", s2, s[4], s[3], s[2], s[5]);
	}
}