#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string t, s = "QWERTYUIOP[]\\ASDFGHJKL;\'ZXCVBNM,./";

inline int isin(char a)
{
	int i;
	for (i = 0; i < s.size(); i++)
	{
		if (s[i] == a) return i;
	}
	return -1;
}

int main()
{
	int i, m;
	while (getline(cin, t))
	{
		for (i = 0; i < t.size(); i++)
		{
			m = isin(t[i]);
			if (m < 0) putchar(t[i]);
			else putchar(s[m - 1]);
		}
		puts("");
	}
}