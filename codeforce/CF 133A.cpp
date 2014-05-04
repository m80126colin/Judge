#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int isout(string s)
{
	int i;
	for (i = 0; i < s.size(); i++)
	{
		if (s[i] == 'H' || s[i] == 'Q' || s[i] =='9')
			return 1;
	}
	return 0;
}

int main()
{
	string s;
	int i;
	while (getline(cin, s))
	{
		if (isout(s))
			puts("YES");
		else puts("NO");
	}
}