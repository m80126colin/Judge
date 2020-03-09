/**
 *  @judge CPE
 *  @id 10421
 *  @source UVa 10193
 * 
 *  @tag Easy, String, Gcd, Number Theory
 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int gcd(int a, int b)
{
	return (b) ? gcd(b, a%b): a;
}

int vert(string s)
{
	int d = 0, i;
	for (i = 0; i < s.size(); i++)
	{
		d = d * 2 + s[i] - '0';
	}
	return d;
}

int main()
{
	string s, t;
	int n, ctr, a, b;
	for (cin >> n, ctr = 1; ctr <= n; ctr++)
	{
		cin >> s >> t;
		a = vert(s);
		b = vert(t);
		if (gcd(a, b) > 1) printf("Pair #%d: All you need is love!\n", ctr);
		else printf("Pair #%d: Love is not all you need!\n", ctr);
	}
}