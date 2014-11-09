#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define MAXL 110
char str[MAXL];

int isvowel(char ch)
{
	return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w+", stdout);
	int t, cnt, len, mx, cur;
	int i, j, n;
	long long ans;
	for (scanf("%d", &t), cnt = 1; cnt <= t; cnt++)
	{
		scanf("%s%d", str, &n);
		len = strlen(str);
		ans = 0;
		for (i = 0; i < len; i++)
		{
			mx = cur = 0;
			for (j = i; j < len; j++)
			{
				if (isvowel(str[j])) cur = 0;
				else cur++;
				mx = max(cur, mx);
				if (mx >= n) ans++;
			}
		}
		printf("Case #%d: %lld\n", cnt, ans);
	}
}