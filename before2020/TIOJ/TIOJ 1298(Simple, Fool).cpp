/**
 *  @judge TIOJ
 *  @id 1298
 *  @tag Simple, Fool
 */
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int mx, mn;
	int n, po, avg, i, tmp;
	while (scanf("%d", &n) != EOF)
	{
		for (po = avg = i = 0; i < n; i++)
		{
			scanf("%d", &tmp);
			if (i)
			{
				if (abs(tmp) > mx) mx = abs(tmp);
				if (abs(tmp) < mn) mn = abs(tmp);
			}
			else mx = mn = abs(tmp);
			avg += abs(tmp);
			po += (tmp > 0);
		}
		printf("Average time: %.3lf sec(s).\nWinning rate: %.3lf %%.\n", (double) (avg - mx - mn) / (n - 2), (double) po * 100 / n);
	}
}