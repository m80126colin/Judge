#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

#define MAX 256
char ch[MAX];
int next[MAX], start;

int main()
{
	int t, n, i, tmp;
	for (scanf("%d", &t); t; t--)
	{
		scanf("%d", &n);
		for (i = 0; i < n; i++)
		{
			scanf("%d", &tmp);
			if (!i) start = tmp;
			cin >> ch[tmp];
			scanf("%d", &next[tmp]);
		}
		for (i = 0; i < n; i++)
		{
			putchar(ch[start]);
			start = next[start];
		}
		puts("");
	}
}