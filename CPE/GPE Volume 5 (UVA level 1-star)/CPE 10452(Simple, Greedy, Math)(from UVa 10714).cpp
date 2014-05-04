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
	int L, n, t, i, tmp, mxl, mnl;
	for (cin >> t; t; t--)
	{
		cin >> L >> n;
		mxl = mnl = 0;
		for (i = 0; i < n; i++)
		{
			cin >> tmp;
			mnl = max(mnl, min(tmp, L - tmp));
			mxl = max(mxl, max(tmp, L - tmp));
		}
		printf("%d %d\n", mnl, mxl);
	}
}