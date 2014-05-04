#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int a, c, n;
	for (cin >> n; n; n--)
	{
		cin >> c >> a;
		printf("%.3lf\n", (double) a * sqrt((double)a*a - c*c) * acos(-1.0) / 4.0);
	}
}