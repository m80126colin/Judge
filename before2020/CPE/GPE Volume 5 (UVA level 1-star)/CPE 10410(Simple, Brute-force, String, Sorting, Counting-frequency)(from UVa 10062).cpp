/**
 *  @judge CPE
 *  @id 10410
 *  @tag Simple, Brute force, String, Sortings, Counting frequency
 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
#define AM 128
using namespace std;

struct ascii{
	int a, b;
}asc[AM];

bool cmp(ascii x, ascii y)
{
	return x.b < y.b || (x.b == y.b && x.a > y.a);
}

int main()
{
	int i, ctr;
	string s;
	ctr = 0;
	while (getline(cin, s))
	{
		memset(asc, 0, sizeof(asc));
		for (i = 0; i < AM; i++) asc[i].a = i;
		for (i = 0; i < s.size(); i++)
			if (s[i] > 32 && s[i] < 128) asc[s[i]].b++;
		sort(asc, asc + AM, cmp);
		if (ctr) puts("");
		for (i = 0; i < AM; i++)
		{
			if (asc[i].b) printf("%d %d\n", asc[i].a, asc[i].b);
		}
		ctr++;
	}
}