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