#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int t, n, i, d;
	int a, b, c;
	for (cin >> t; t; t--)
	{
		cin >> n;
		d = 0;
		for (i = 0; i < n; i++)
		{
			cin >> a >> b >> c;
			d += a * c;
		}
		cout << d << endl;
	}
}