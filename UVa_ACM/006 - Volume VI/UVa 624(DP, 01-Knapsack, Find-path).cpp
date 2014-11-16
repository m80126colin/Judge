#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

#define N 10010
#define T 10010
int n, t, mx, dp[N], a[T];
string path[N];

int main()
{
	while (scanf("%d", &n) != EOF)
	{
		scanf("%d", &t);
		for (int i = 0; i < t; i++)
			scanf("%d", &a[i]);
		memset(dp, -1, sizeof(dp));
		dp[0] = mx = 0;
		path[0] = "";
		for (int j = 0; j < t; j++)
			for (int i = n; i >= a[j]; i--)
				if (dp[i - a[j]] >= 0)
				{
					dp[i] = a[j];
					char tmp[10];
					sprintf(tmp, "%d", a[j]);
					path[i] = path[i - a[j]] + string(tmp) + ' ';
					if (i > mx) mx = i;
				}
		printf("%ssum:%d\n", path[mx].c_str(), mx);
	}
}