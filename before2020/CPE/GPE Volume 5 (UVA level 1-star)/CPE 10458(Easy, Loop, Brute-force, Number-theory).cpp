/**
 *  @judge CPE
 *  @id 10458
 *  @source UVa 10922
 * 
 *  @tag Easy, Loop, Brute force, Number Theory
 */
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void sum(int &x)
{
	int i;
	for (i = 0; x; x /= 10) i += x%10;
	x = i;
	return;
}

int main()
{
	int i, d, ctr;
	string s;
	while (cin >> s, s != "0")
	{
		for (i = d = 0; i < s.size(); i++) d += s[i] - '0';
		for (ctr = 0; !(d % 9); sum(d))
		{
			ctr++;
			if (d == 9) break;
		}
		cout << s;
		if (ctr) printf(" is a multiple of 9 and has 9-degree %d.\n", ctr);
		else puts(" is not a multiple of 9.");
	}
}