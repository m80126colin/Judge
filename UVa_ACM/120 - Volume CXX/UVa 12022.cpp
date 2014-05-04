#include <stdio.h>

int main() {
    static int i, j, n, pas[12][12], sum[12] = {0};
    pas[0][0] = pas[1][0] = pas[1][1] = 1;
    for (i = 2; i <= 11; i++) {
        pas[i][0] = pas[i][i] = 1;
        for (j = 1; j < i; j++) pas[i][j] = pas[i-1][j-1] + pas[i-1][j];
    }
    for (i = 1; i <= 11; i++) {
        sum[i] = 1;
        for (j = 1; j < i; j++) sum[i] += pas[i][j] * sum[j];
    }
    int t;
    for (scanf("%d", &t), i = 1; i <= t; i++) {
        scanf("%d", &n);
        printf("%d\n", sum[n]);
    }
}
