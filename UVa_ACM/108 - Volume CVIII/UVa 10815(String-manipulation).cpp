#include <stdio.h>
#include <iostream>
#include <set>
#include <string>
#include <ctype.h>
using namespace std;

set <string> S;
set <string>::iterator it;

int main()
{
	char ch;
	S.clear();
	while (cin.peek() != EOF)
	{
		ch = getchar();
		if (isalpha(ch))
		{
			string tmp = "";
			while (isalpha(ch))
			{
				tmp += tolower(ch);
				ch = getchar();
			}
			S.insert(tmp);
		}
	}
	for (it = S.begin(); it != S.end(); it++)
		cout << *it << endl;
}