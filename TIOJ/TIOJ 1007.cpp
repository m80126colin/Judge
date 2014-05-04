#include <stdio.h>
#include <string.h>
int main() {
	unsigned long long n, m, i, j, ans, dp[100][100];
	while (scanf("%llu%llu",&n,&m)!=EOF) {
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		for (i = 0; i <= m; i++) {
			for (j = 0; j <= n; j++) {
				dp[i+1][0] += dp[i][j];
				dp[i+1][j+1] += dp[i][j];
			}
		}
		for (ans = i = 0; i <= n; i++) ans += dp[m][i];
		printf("%I64u\n", ans);
	}
}