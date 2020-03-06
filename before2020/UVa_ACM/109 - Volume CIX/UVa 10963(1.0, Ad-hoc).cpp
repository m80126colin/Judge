/**
 *  @judge UVa
 *  @id 10963
 *  @tag 1.0, Ad hoc
 */
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main()
{
	int t, w, gap, a, b, flag;
	for (scanf("%d", &t); t; t--)
	{
		flag = 1;
		for (scanf("%d", &w), gap = -1; w; w--)
		{
			scanf("%d%d", &a, &b);
			if (gap == -1) gap = abs(a - b);
			else if (gap != abs(a - b)) flag = 0;
		}
		if (flag) puts("yes");
		else puts("no");
		if (t > 1) puts("");
	}
}