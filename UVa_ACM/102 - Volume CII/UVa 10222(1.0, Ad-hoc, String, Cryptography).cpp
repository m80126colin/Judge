#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

string str, word = "`1234567890-=qwertyuiop[]asdfghjkl;'zxcvbnm,./";

int main()
{
	int i, pos;
	while (getline(cin, str))
	{
		for (i = 0; i < str.size(); i++)
			if ((pos = word.find(str[i])) != string::npos)
				str[i] = word[pos - 2];
		puts(str.c_str());
	}
}