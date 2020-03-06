/**
 *  @judge UVa
 *  @id 11192
 *  @tag 1.0, Ad hoc, String, Reverse
 */
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

#define MAX 110
int n, m;
char str[MAX], tar[MAX];

void reverse(char *source, char *target)
{
	int i, j, len = strlen(source);
	m = len / n;
	target[len] = '\0';
	for (i = 0; i < len; i += m)
		for (j = 0; j < m; j++)
			target[i + j] = source[i + m - j - 1];
	return ;
}

int main()
{
	while (scanf("%d", &n), n)
	{
		scanf("%s", str);
		reverse(str, tar);
		puts(tar);
	}
}