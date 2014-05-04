#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

int main()
{
	int num, way, i, Vt, V0, mlen, tmp;
	while (scanf("%d%d", &Vt, &V0), (Vt || V0))
	{
		mlen = 0;
		num = 1;
		for (i = 1; Vt > V0 * i; i++)
		{
			tmp = (Vt - V0 * i) * i;
			if (tmp > mlen)
			{
				mlen = tmp;
				num = i;
				way = 1;
			}
			else if (tmp == mlen) way++;
		}
		if (mlen == 0 || way > 1) puts("0");
		else printf("%d\n", num);
	}
}