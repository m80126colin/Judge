#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

#define MAX 110
char s1[MAX], s2[MAX];

int check()
{
	int i, len1, len2;
	len1 = strlen(s1);
	len2 = strlen(s2);
	if (len1 != len2)
		return 0;
	for (i = 0; i < len1; i++)
		if (s1[i] != 'a' && s1[i] != 'e' && s1[i] != 'i' && s1[i] != 'o' && s1[i] != 'u')
		{
			if (s1[i] != s2[i])
				return 0;
		}
		else if (s2[i] != 'a' && s2[i] != 'e' && s2[i] != 'i' && s2[i] != 'o' && s2[i] != 'u')
			return 0;
	return 1;
}

int main()
{
	int t;
	for (scanf("%d", &t); t; t--)
	{
		scanf("%s%s", s1, s2);
		if (check()) puts("Yes");
		else puts("No");
	}
}