#include <iostream>
#include <string>
#include <ctype.h>
#include <stdio.h>
using namespace std;

int main()
{
	int n, i;
	string s;
	for (scanf("%d", &n); n; n--)
	{
		cin >> s;
		for (i = s.size() - 1; i >= 0; i--)
		{
			putchar( ((s.size() - 1 - i)? tolower(s[i]): toupper(s[i])) );
		}
		puts("");
	}
}