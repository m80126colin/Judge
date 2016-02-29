#include <stdio.h>
#include <iostream>
using namespace std;

struct cloc
{
	int hh, mm, ss;
	double operator - (const cloc& A)
	{
		cloc B;
		B.hh = hh - A.hh;
		B.mm = mm - A.mm;
		B.ss = ss - A.ss;
		if (B.ss < 0) B.ss += 60, B.mm--;
		if (B.mm < 0) B.mm += 60, B.hh--;
		return (double) B.hh + B.mm / 60.0 + B.ss / 3600.0;
	}
}old_c, new_c;

double ttl, sp;

int main()
{
	sp = ttl = 0;
	if (scanf("%d:%d:%d", &old_c.hh, &old_c.mm, &old_c.ss) == EOF) return 0;
	if (cin.peek() == '\n')
		printf("%02d:%02d:%02d %.2lf km\n", old_c.hh, old_c.mm, old_c.ss, ttl);
	else scanf("%lf", &sp);
	while (scanf("%d:%d:%d", &new_c.hh, &new_c.mm, &new_c.ss) != EOF)
	{
		ttl += (new_c - old_c) * sp;
		if (cin.peek() == '\n')
			printf("%02d:%02d:%02d %.2lf km\n", new_c.hh, new_c.mm, new_c.ss, ttl);
		else scanf("%lf", &sp);
		old_c = new_c;
	}
}