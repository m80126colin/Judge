#include <stdio.h>
#define nMOD 10056

int main() {
    static int i, j, n, pas[1001][1001], sum[1001] = {0};
    pas[0][0] = pas[1][0] = pas[1][1] = 1;
    for (i = 2; i <= 1000; i++) {
        pas[i][0] = pas[i][i] = 1;
        for (j = 1; j < i; j++) pas[i][j] = (pas[i-1][j-1] + pas[i-1][j]) % nMOD;
    }
    for (i = 1; i <= 1000; i++) {
        sum[i] = 1;
        for (j = 1; j < i; j++) {
            sum[i] += pas[i][j] * sum[j];
            sum[i] %= nMOD;
        }
    }
    int t;
    for (scanf("%d", &t), i = 1; i <= t; i++) {
        scanf("%d", &n);
        printf("Case %d: %d\n", i, sum[n]);
    }
}
