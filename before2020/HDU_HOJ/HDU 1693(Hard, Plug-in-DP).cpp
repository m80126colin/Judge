#include <stdio.h>
#include <string.h>

int n, m, board[12];
long long dp[12][12][1<<12];

void sol() {
     int i, j, s, a, b;
     memset(dp, 0, sizeof(dp));
     dp[0][m][0] = 1;
     for (i = 1; i <= n; i++) {
         for (s = 0; s < (1 << m); s++) dp[i][0][s << 1] = dp[i - 1][m][s];
         for (j = 1; j <= m; j++) {
             for (s = 0; s < (1 << (m + 1)); s++) {
                 a = 1 << j, b = a >> 1;
                 if (board[i] & (1 << j)) {
                    dp[i][j][s] += dp[i][j - 1][s ^ a ^ b];
                    if (((s & a) != 0) ^ ((s & b) != 0)) dp[i][j][s] += dp[i][j - 1][s];
                 }
                 else {
                    if (((s & a) == 0) && ((s & b) == 0)) dp[i][j][s] += dp[i][j - 1][s];
                    else dp[i][j][s] = 0;
                 }
             }
         }
     }
     return;
}

int main() {
    int i, j, t, tmp, tc = 0;
    for (scanf("%d", &t), tc = 1; tc <= t; tc++) {
        scanf("%d%d", &n, &m);
        memset(board, 0, sizeof(board));
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) {
                scanf("%d", &tmp);
                if (tmp) board[i] |= (1<<j);
            }
        }
        sol();
        printf("Case %d: There are %I64d ways to eat the trees.\n", tc, dp[n][m][0]);
    }
}
