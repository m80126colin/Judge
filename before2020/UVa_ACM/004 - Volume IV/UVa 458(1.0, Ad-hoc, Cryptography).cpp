#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

#define K ('J'-'C')
string str;

int main()
{
	int i;
	while (getline(cin, str))
	{
		for (i = 0; i < str.size(); i++)
			str[i] -= K;
		puts(str.c_str());
	}
}