#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string s="qwertyuiop[]\\asdfghjkl;\'zxcvbnm,./";

int isin(char x)
{
	int i;
	for (i = 2; i < s.size(); i++)
	{
		if (x == s[i]) return i;
	}
	return -1;
}

int main()
{
	int i, n;
	string t;
	while (getline(cin, t))
	{
		for (i = 0; i < t.size(); i++)
		{
			if (t[i] >= 'A' && t[i] <= 'Z') t[i] = t[i] - 'A' + 'a';
			n = isin(t[i]);
			if (n > 0) putchar(s[n - 2]);
			else putchar(t[i]);
		}
		puts("");
	}
}