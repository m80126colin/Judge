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
	int t, n, m;
	for (cin >> t; t; t--)
	{
		cin >> n >> m;
		cout << (n/3) * (m/3) << endl;
	}
}