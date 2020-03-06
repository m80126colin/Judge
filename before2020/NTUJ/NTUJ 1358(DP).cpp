/**
 *  @judge NTUJ
 *  @id 1358
 *  @tag DP
 */
#include <stdio.h>
#include <iostream>
#include <string.h>
#define MAX 50010
#define iMAX 2147483647
using namespace std;

int a[MAX], p[MAX], h[MAX], dp[MAX][2], n, k;

inline int minvalue(int left, int right) {
    int i, tmp, sum, middle = (left + right)/2;
    if (left == right) return middle;
    tmp = sum = 0;
    for (i = 1; i <= n; i++) {
        if (sum >= k) return minvalue(middle + 1, right);
        if (p[i] - p[tmp] > middle) {
                 if (i == tmp + 1 || sum >= k) return minvalue(middle + 1, right);
                 tmp = i - 1;
                 sum++;
                 i--;
        }
    }
    return minvalue(left, middle);
}

inline int ans(int mv) {
    int i, j, x, m;
    dp[0][0] = 1;
    for (i = 1; i <= n; i++) {
        if (p[i] <= mv) dp[i][1] = 1;
        dp[i][1] += dp[i-1][1];
    }
    m = dp[n][1] - dp[n-1][1];  
    h[0] = 0;
    x = 1;
    for (i = 1; i <= n; i++) {
        while (p[i] - p[x-1] > mv) x++;
        h[i] = x-1;
    }
    dp[0][0] = dp[0][1] = 0;
    for (j = 2; j <= k; j++) {
        for (i = 1; i <= n; i++) {
            dp[i][0] = dp[i][1];
            dp[i][1] = dp[i-1][1];
            dp[i][1] += dp[i-1][0];
            if (h[i]) dp[i][1] += (10007 - dp[h[i]-1][0]);
            if (dp[i][1] >= 10007) dp[i][1] %= 10007;
        }
        
        m += dp[n][1] + 10007 - dp[n-1][1];
        if (m >= 10007) m %= 10007;
        
    }
    return m;
}

int main() {
    int i, j, x, mv;
    while (scanf("%d%d", &n, &k) != EOF) {
          if (n == 0) {
                puts("0 1");
                continue;
          }
          a[0] = p[0] = 0;
          memset(dp, 0, sizeof(dp));
          for (i = 1; i <= n; i++) {
              scanf("%d", &a[i]);
              p[i] = p[i-1] + a[i];
          }
          mv = minvalue(0, p[n]);
          printf("%d %d\n", mv, ans(mv));
    }
}
