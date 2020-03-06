/**
 *  @judge CPE
 *  @id 10405
 *  @tag Easy, Straight forward
 */
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

int abs(int x)
{
	if (x < 0) return -x;
	return x;
}

int main()
{
	bool ox[3010];
	int n, i, be, af;
	while (cin >> n)
	{
		memset(ox, 1, sizeof(ox));
		cin >> be;
		for (i = 1; i < n; i++)
		{
			cin >> af;
			if (abs(be - af) < n) ox[abs(be - af)] = 0;
			be = af;
		}
		for (i = 1; i < n; i++)
		{
			if (ox[i])
			{
				puts("Not jolly");
				break;
			}
		}
		if (i == n) puts("Jolly");
	}
}