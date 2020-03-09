/**
 *  @judge CPE
 *  @id 10470
 *  @source UVa 11172
 * 
 *  @tag Easy, Comparison operator
 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int t, a, b;
	for (cin >> t; t; t--)
	{
		cin >> a >> b;
		if (a > b) puts(">");
		else if (a < b) puts("<");
		else puts("=");
	}
}