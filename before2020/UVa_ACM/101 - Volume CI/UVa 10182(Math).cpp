#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

int main()
{
	int n, m, x, y, tmp;
	while (scanf("%d", &n) != EOF)
	{
		n--;
		if (n)
		{
			m = (n - 1) / 6;
			m = ( -1 + sqrt((double) 8 * m + 1) ) / 2.0;
			n -= m * (m + 1) * 3 + 1;
			n++;
			m++;
			x = y = 0;
			tmp = n / m;
			if (tmp == 0 || tmp == 5 || tmp == 6) x = m;
			else if (tmp == 2 || tmp == 3) x = -m;
			if (tmp == 1 || tmp == 2) y = m;
			else if (tmp == 4 || tmp == 5) y = -m;
			n %= m;
			if (tmp == 3 || tmp == 4) x += n;
			else if (tmp == 0 || tmp == 1) x -= n;
			if (tmp == 0 || tmp == 5) y += n;
			else if (tmp == 2 || tmp == 3) y -= n;
			printf("%d %d\n", x, y);
		}
		else puts("0 0");
	}
}