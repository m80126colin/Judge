#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 10010
int tmp[MAX], tlen, pos, a[MAX], n;
int LIS[MAX], LDS[MAX];

int main()
{
	int i, ans;
	while (scanf("%d", &n) != EOF)
	{
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);
		for (tlen = i = 0; i < n; i++) // LIS
		{
			pos = lower_bound(tmp, tmp + tlen, a[i]) - tmp;
			LIS[i] = pos + 1;
			if (pos == tlen) tmp[tlen++] = a[i];
			else if (a[i] < tmp[pos]) tmp[pos] = a[i];
		}
		for (tlen = i = 0; i < n; i++) // LDS
		{
			pos = lower_bound(tmp, tmp + tlen, a[n - i - 1]) - tmp;
			LDS[n - i - 1] = pos + 1;
			if (pos == tlen) tmp[tlen++] = a[n - i - 1];
			else if (a[n - i - 1] < tmp[pos]) tmp[pos] = a[n - i - 1];
		}
		ans = 1;
		for (i = 0; i < n; i++)
			ans = max(ans, min(LIS[i], LDS[i]) * 2 - 1);
		printf("%d\n", ans);
	}
}