/**
 *  @judge UVa
 *  @id 494
 *  @tag 1.0, Ad hoc, Count word
 */
#include <stdio.h>
#include <string>
#include <ctype.h>
#include <iostream>
using namespace std;

int count;
bool flag;
string str;

int main()
{
	int i, flag;
	while (getline(cin, str))
	{
		count = flag = 0;
		for (i = 0; i < str.size(); i++)
		{
			if (flag ^ (isalpha(str[i]) != 0))
			{
				if (flag) count++;
				flag = !flag;
			}
		}
		printf("%d\n", count);
	}
}