/**
 *  @judge UVa
 *  @id 401
 *  @tag Palindrome, String Manipulation
 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
#include <string>
using namespace std;

string m = "A   3  HIL JM O   2TUVWXY501SE Z  8 ";
string t[4] = {" -- is not a palindrome.", " -- is a regular palindrome.", " -- is a mirrored string.", " -- is a mirrored palindrome."};

int mirror(string s)
{
	int i, len = s.size() / 2;
	for (i = 0; i <= len; i++)
	{
		if ((s[i] == '0' || s[i] == 'O') && (s[s.size() - 1 - i] == '0' || s[s.size() - 1 - i] == 'O')) continue;
		if (m[(isdigit(s[i])? (s[i] - '0' + 26): (s[i] - 'A'))] != s[s.size() - 1 - i])
			return 0;
	}
	return 1;
}

int palindrome(string s)
{
	int i, len = s.size() / 2;
	for (i = 0; i < len; i++)
	{
		if (s[i] != s[s.size() - 1 - i])
			return 0;
	}
	return 1;
}

int main()
{
	int st;
	string s;
	while (cin >> s)
	{
		st = (mirror(s) << 1) + palindrome(s);
		cout << s << t[st] << endl << endl;
	}
}