#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;
typedef long long llong;

llong Gcd(llong a, llong b)
{
	if (b) return Gcd(b, a % b);
	return a;
}

llong ExtGcd(llong a, llong b, llong &x, llong &y)
{
	if (b)
	{
		llong d = ExtGcd(b, a % b, y, x);
		y -= a / b * x;
		return d;
	}
	x = 1;
	y = 0;
	return a;
}

int main()
{
	llong n, g, a[4], i, x, y;
	llong x1, y1, x2, y2, ansx, ansy;
	while (scanf("%lld", &n), n)
	{
		for (i = 0; i < 4; i++)
			scanf("%lld", &a[i]);
		g = Gcd(a[1], a[3]);
		if (n % g) puts("failed");
		else
		{
			n /= g; a[1] /= g; a[3] /= g;
			g = ExtGcd(a[1], a[3], x, y);
			x *= n; y *= n;

			llong X = (llong) ceil((double) -x / a[3]), Y = (llong) floor((double) y / a[1]);
			if (X > Y) puts("failed");
			else
			{
				x1 = x + X * a[3];
				y1 = y - X * a[1];

				x2 = x + Y * a[3];
				y2 = y - Y * a[1];

				if (x1 * a[0] + y1 * a[2] < x2 * a[0] + y2 * a[2])
				{
					ansx = x1;
					ansy = y1;
				}
				else
				{
					ansx = x2;
					ansy = y2;
				}
				printf("%lld %lld\n", ansx, ansy);
			}
		}
	}
}