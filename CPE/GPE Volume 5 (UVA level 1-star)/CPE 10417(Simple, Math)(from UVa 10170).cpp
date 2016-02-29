#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

int main()
{
	long long s, d, D, rt, ans;
	while (scanf("%lld%lld", &s, &d) != EOF)
	{
		D = (2 * s - 1) * (2 * s - 1) + 8 * d;
		rt = sqrt((double) D);
		ans = (- (2 * s + 1) + rt) / 2;
		if (rt * rt != D) ans++;
		printf("%lld\n", s + ans);
	}
}