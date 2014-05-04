#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

#define MAX 100010
char s[MAX], t[MAX];

int main()
{
	int i, j, slen, tlen;
	while (scanf("%s%s", &s, &t) != EOF)
	{
		slen = strlen(s);
		tlen = strlen(t);
		for (i = j = 0; i < slen && j < tlen; j++)
			if (s[i] == t[j]) i++;
		if (i == slen) puts("Yes");
		else puts("No");
	}
}