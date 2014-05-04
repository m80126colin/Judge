#include <iostream>
#include <string>
#include <ctype.h>
#include <stdio.h>
using namespace std;

string s;

int ispalindrome()
{
	int i, len = s.size() / 2;
	for (i = 0; i < len; i++)
		if (s[i] != s[s.size() - 1 - i])
			return 0;
	return 1;
}

int main()
{
	
	while (getline(cin, s))
	{
		cout << s;
		puts( ((ispalindrome())? " is a palindrome.": " is not a palindrome.") );
	}
}