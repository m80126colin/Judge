#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s;

inline void decode()
{
	char tmp;
	string t = "";
	reverse(s.begin(), s.end());
	for (int i = 0; i < s.size(); i += 2)
	{
		tmp = atoi(s.substr(i, 2).c_str());
		if ( !((tmp >= 'a' && tmp <= 'z') || (tmp >= 'A' && tmp <= 'Z') || (tmp == ' ') || (tmp == '!') || (tmp == ',') || (tmp == '.') || (tmp == ':') || (tmp == ';') || (tmp == '?')) )
		{
			tmp = atoi(s.substr(i, 3).c_str());
			i++;
		}
		t += tmp;
	}
	puts(t.c_str());
	return;
}

inline void encode()
{
	int tmp;
	string t = "";
	char tt[5];
	for (int i = 0; i < s.size(); i++)
	{
		tmp = s[i];
		sprintf(tt, "%d", tmp);
		t += tt;
	}
	reverse(t.begin(), t.end());
	puts(t.c_str());
	return;
}

int main()
{
	while (getline(cin, s))
	{
		if (s[0] >= '0' && s[0] <= '9') decode();
		else encode();
	}
}