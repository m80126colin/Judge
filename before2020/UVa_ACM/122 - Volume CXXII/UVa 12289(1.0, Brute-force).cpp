/**
 *  @judge UVa
 *  @id 12289
 *  @tag 1.0, Brute force
 */
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int Check(string s, string t)
{
	if (s.size() != t.size())
		return 0;
	int i, j;
	string tmp = t;
	for (i = 0; i < t.size(); i++)
	{
		for (j = 0; j < 26; j++)
		{
			tmp[i] = j + 'a';
			if (tmp == s) return 1;
		}
		tmp[i] = t[i];
	}
	return 0;
}

int main()
{
	int t;
	string s;
	for (scanf("%d", &t); t; t--)
	{
		cin >> s;
		if (Check(s, "one")) puts("1");
		else if (Check(s, "two")) puts("2");
		else puts("3");
	}
}