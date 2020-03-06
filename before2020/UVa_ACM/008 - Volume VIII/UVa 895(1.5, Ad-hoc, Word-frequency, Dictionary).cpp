/**
 *  @judge UVa
 *  @id 895
 *  @tag 1.5, Ad-hoc, Word frequency, Dictionary
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <iostream>
using namespace std;

#define MAX 1010
#define WMAX 26
int test[WMAX], word[MAX][WMAX], n;
char str[MAX];

int main()
{
	int i, j, len, ans;
	for (n = 0; scanf("%s", str), str[0] != '#'; n++)
	{
		for (i = 0; i < WMAX; i++)
			word[n][i] = 0;
		len = strlen(str);
		for (i = 0; i < len; i++)
			word[n][str[i] - 'a']++;
	}
	cin.ignore(1);
	while (gets(str), str[0] != '#')
	{
		for (i = 0; i < WMAX; i++)
			test[i] = 0;
		len = strlen(str);
		for (i = 0; i < len; i++)
			if (isalpha(str[i]))
				test[str[i] - 'a']++;
		ans = 0;
		for (j = 0; j < n; j++)
		{
			for (i = 0; i < WMAX; i++)
				if (test[i] < word[j][i])
					break;
			if (i == WMAX) ans++;
		}
		printf("%d\n", ans);
	}
}