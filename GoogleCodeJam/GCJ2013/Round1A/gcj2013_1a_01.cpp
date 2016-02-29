#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int T, cnt;
long long r, t;

long long sol()
{
	long long left, right, middle;
	left = 1;
	right = 707106780 + 1;
	while (right - left > 1)
	{
		middle = (left + right) / 2;
		if (2 * middle + 2 * r - 1 <= t / middle) left = middle;
		else right = middle;
	}
	return left;
}

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w+", stdout);
	for (scanf("%d", &T), cnt = 1; cnt <= T; cnt++)
	{
		scanf("%lld%lld", &r, &t);
		printf("Case #%d: %lld\n", cnt, sol());
	}
}