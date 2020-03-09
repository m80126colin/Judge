/**
 *  @judge CPE
 *  @id 10443
 *  @source UVa 10473
 * 
 *  @tag Easy, String Manipulation, Number Base Conversion
 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

inline void base(string s, int w, int b)
{
	int i, d = 0;
	for (i = 0; i < s.size(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9') d = d * w + s[i] - '0';
		else d = d * w + s[i] - 'A';
	}
	if (b == 10) printf("%d\n", d);
	else printf("0x%X\n", d);
}

int main()
{
	char s[100];
	while (cin >> s)
	{
		if (s[0] == '-') break;
		if (strlen(s) > 2 && s[1] == 'x') base(s+2, 16, 10);
		else base(s, 10, 16);
	}
}