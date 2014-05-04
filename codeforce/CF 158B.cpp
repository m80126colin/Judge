#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

int main()
{
	int n, m, cnt[4];
	while (scanf("%d", &n) != EOF)
	{
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &m);
			cnt[m % 4]++;
		}
		if (cnt[1] > cnt[3])
		{
			cnt[0] += cnt[3];
			cnt[1] -= cnt[3];
			cnt[3] = 0;
		}
		else
		{
			cnt[0] += cnt[1];
			cnt[3] -= cnt[1];
			cnt[1] = 0;
		}
		if (cnt[1] >= 2 * cnt[2])
		{
			cnt[0] += cnt[2];
			cnt[1] -= 2 * cnt[2];
			cnt[2] = 0;
			cnt[0] += cnt[1] / 4;
			cnt[1] -= (cnt[1] / 4) * 4;
		}
		else
		{
			cnt[0] += cnt[1] / 2;
			cnt[2] -= cnt[1] / 2;
			cnt[1] -= (cnt[1] / 2) * 2;
			cnt[0] += cnt[2] / 2;
			cnt[2] -= (cnt[2] / 2) * 2;
			if (cnt[1] && cnt[2])
				cnt[3]++, cnt[1] = cnt[2] = 0;
		}
		if (cnt[1]) cnt[1] = 1;
		printf("%d\n", cnt[0] + cnt[3] + cnt[2] + cnt[1]);
	}
}