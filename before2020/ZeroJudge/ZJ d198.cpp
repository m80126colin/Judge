#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

int n, m;
long long map[110][110], dp[110][110];

int main() {
	int t, ctr;
	int a, b, i, j;
	for (scanf("%d", &t), ctr = 0; ctr < t; ctr++) {
		if (ctr) puts("");
		memset(map, 0, sizeof(map));
		memset(dp, 0, sizeof(dp));
		scanf("%d%d",&n,&m);
		for (i = 1; i <= n; i++) {
			scanf("%d", &a);
			while (cin.peek() != '\n') {
				scanf("%d", &b);
				map[a][b] = 1;
			}
		}
		dp[1][0] = 1;
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= m; j++) {
				if (!map[i][j]) dp[i][j] = dp[i-1][j] + dp[i][j-1];
			}
		}
		printf("%lld\n", dp[n][m]);
	}
}