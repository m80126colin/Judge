#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int a[10010], ox[10010];

int main()
{
	int ctr;
	int n, q, i, tmp;
	ctr = 1;
	while (cin >> n >> q, (n || q))
	{
		memset(ox, 0, sizeof(ox));
		for (i = 0; i < n; i++) cin >> a[i];
		sort(a, a+n);
		for (i = 0; i < n; i++)
		{
			if (!ox[a[i]]) ox[a[i]] = i+1;
		}
		printf("CASE# %d:\n", ctr);
		for (i = 0; i < q; i++)
		{
			cin >> tmp;
			if (ox[tmp]) printf("%d found at %d\n", tmp, ox[tmp]);
			else printf("%d not found\n", tmp);
		}
		ctr++;
	}
}