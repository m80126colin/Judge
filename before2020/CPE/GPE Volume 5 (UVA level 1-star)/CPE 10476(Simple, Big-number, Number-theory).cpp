/**
 *  @judge CPE
 *  @id 10476
 *  @source UVa 11344
 * 
 *  @tag Simple, Big number, Number Theory
 */
#include <stdio.h>
#include <iostream>
#include <string>
#define M 479001600LL
using namespace std;

string s;

inline void input(long long &d)
{
	int len = s.size(), i;
	d = 0;
	for (i = 0; i < len; i++)
	{
		d *= 10;
		d += s[i] - '0';
		d %= M;
	}
	return ;
}

int main()
{
	int t, n, i, p, flag;
	long long d;
	for (scanf("%d", &t); t; t--)
	{
		cin >> s;
		input(d);
		flag = 1;
		for (scanf("%d", &n), i = 0; i < n; i++)
		{
			scanf("%d", &p);
			if (d % p) flag = 0;
		}
		cout << s << " - ";
		if (flag) puts("Wonderful.");
		else puts("Simple.");
	}
}