#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int pos(int x)
{
	if (x == 0) return 0;
	return sqrt((double) x);
}

int main()
{
	int a, b;
	while (cin >> a >> b, (a || b)) cout << pos(b) - pos(a - 1) << endl;
}