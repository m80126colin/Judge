#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
	int n, m, a, i, ta, ti, md;
	while (scanf("%d", &n), n != -1)
	{
		ta = n, ti = 0, md = 1;
		for (m = sqrt((double) n); m; m--)
		{
			if (!(n % m))
			{
				if ((n / m) & 1)
				{
					a = (n / m - 1) >> 1;
					i = m;
					if (a - (i - 1) > 0 && 2 * i >= 2 * ti + md)
						ti = i, ta = a, md = 0;
					a = m;
					i = (n / m - 1) >> 1;
					if (a - i > 0 && 2 * i + 1 >= 2 * ti + md)
						ti = i, ta = a, md = 1;
				}
				if (m & 1)
				{
					a = (m - 1) >> 1;
					i = n / m;
					if (a - (i - 1) > 0 && 2 * i >= 2 * ti + md)
						ti = i, ta = a, md = 0;
					a = n / m;
					i = (m - 1) >> 1;
					if (a - i > 0 && 2 * i + 1 >= 2 * ti + md)
						ti = i, ta = a, md = 1;
				}
			}
		}
		printf("%d = %d + ... + %d\n", n, ta - ti + (!md), ta + ti);
	}
}