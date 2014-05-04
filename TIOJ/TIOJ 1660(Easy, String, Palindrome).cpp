#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

inline int ispalin(string s)
{
	int i, len = s.size() / 2;
	for (i = 0; i < len; i++)
		if (s[i] != s[s.size() - i - 1])
			return 0;
	return 1;
}

int main()
{
	string s;
	while (getline(cin, s))
		puts((ispalin(s))?"palindrome":"not palindrome");
}