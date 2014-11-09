#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 26
#define MAXN 510
int ch[MAX], len, m;
char str[MAXN];

int main()
{
	freopen("beautiful_stringstxt.txt", "r", stdin);
	freopen("beautiful_stringstxt.out", "w+", stdout);
	int i, ans, cnt;
	for (scanf("%d", &m), getchar(), cnt = 1; cnt <= m; cnt++)
	{
		gets(str);
		memset(ch, 0, sizeof(ch));
		len = strlen(str);
		for (i = 0; i < len; i++)
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
				ch[str[i] - 'A']++;
			if (str[i] >= 'a' && str[i] <= 'z')
				ch[str[i] - 'a']++;
		}
		sort(ch, ch + MAX);
		ans = 0;
		for (i = MAX; i && ch[i - 1]; i--)
			ans += i * ch[i - 1];
		printf("Case #%d: %d\n", cnt, ans);
	}
}