/**
 *  @judge UVa
 *  @id 740
 *  @tag Easy, Simulation
 */
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

string cha[2], ins;

int myatoi(string str, int base)
{
	int i, ans = 0;
	for (i = 0; i < str.size(); i++)
	{
		ans *= base;
		ans += str[i] - '0';
	}
	return ans;
}

int main()
{
	int i, j, flag = 0;
	for (i = 0; i < 2; i++)
		getline(cin, cha[i]);
	while (cin >> ins)
	{
		flag = 0;
		for (i = 0; i < ins.size(); i += 5)
		{
			j = myatoi(ins.substr(i, 5), 2);
			if (j == 31) flag = 1;
			else if (j == 27) flag = 0;
			else putchar(cha[flag][j]);
		}
		puts("");
	}
}