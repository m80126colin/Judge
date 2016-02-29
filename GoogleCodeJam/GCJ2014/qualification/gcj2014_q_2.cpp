#include <cstdio>
#include <iostream>
using namespace std;

#define EPS 1e-7
#define ZERO(x) (((x) < -EPS)? -1: (((x) > EPS)? 1: 0))

int main()
{
	//freopen("B-large.in", "r+", stdin);
	//freopen("B-large.out", "w+", stdout);
	int t, cnt;
	double c, f, x, cp, cs;
	for (scanf("%d", &t), cnt = 1; cnt <= t; cnt++)
	{
		scanf("%lf%lf%lf", &c, &f, &x);
		cp = 2.0;
		cs = 0.0;
		while (( ((x - c) / cp) - (x / (cp + f)) ) > 0)
		{
			cs += c / cp;
			cp += f;
		}
		cs += x / cp;
		printf("Case #%d: %.7lf\n", cnt, cs);
	}
}