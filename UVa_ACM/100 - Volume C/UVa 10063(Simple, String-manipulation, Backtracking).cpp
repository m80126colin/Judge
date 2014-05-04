#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
using namespace std;

struct str
{
	char s[15];
	str() {}
}w;
char s[15];
int n;

void backtrack(int i, str t)
{
	int j;
	if (i >= n)
	{
		for (j = i; j; j--) putchar(t.s[j - 1]);
		puts("");
		return ;
	}
	for (j = i; j >= 0; j--)
	{
		t.s[j + 1] = t.s[j];
		t.s[j] = s[i];
		backtrack(i + 1, t);
	}
	return ;
}

int main()
{
	int ok = 0;
	while (scanf("%s", s) != EOF)
	{
		if (ok) puts("");
		n = strlen(s);
		memset(w.s, 0, sizeof(w.s));
		backtrack(0, w);
		ok = 1;
	}
}