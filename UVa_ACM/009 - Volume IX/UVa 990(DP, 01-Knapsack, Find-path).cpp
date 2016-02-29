#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

#define N 1010
#define INF 1010101010
int n, t, w, a[N][2], dp[N], num[N], mx;
string path[N];
char buf[N];

int main()
{
	int cnt;
	for (cnt = 0; scanf("%d%d", &t, &w) != EOF; cnt++)
	{
		t /= (3 * w);
		scanf("%d", &n);
		for (int j = 0; j < n; j++)
			scanf("%d%d", &a[j][0], &a[j][1]);
		dp[0] = num[0] = mx = 0;
		path[0] = "";
		for (int i = 1; i <= t; i++)
			dp[i] = -INF;
		for (int j = 0; j < n; j++)
			for (int i = t; i >= a[j][0]; i--)
				if (dp[i - a[j][0]] >= 0)
				{
					int tmp = i - a[j][0];
					if (dp[i] < dp[tmp] + a[j][1])
					{
						dp[i] = dp[tmp] + a[j][1];
						if (dp[mx] < dp[i]) mx = i;
						sprintf(buf, "%d %d\n", a[j][0], a[j][1]);
						path[i] = path[tmp] + string(buf);
						num[i] = num[tmp] + 1;
					}
				}
		if (cnt) puts("");
		printf("%d\n%d\n%s", dp[mx], num[mx], path[mx].c_str());
	}
}