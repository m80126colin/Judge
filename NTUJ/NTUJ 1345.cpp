#include <stdio.h>

int main() {
    long long n, t, r;
    long long te, remain, team, tol;
    for (scanf("%lld", &te); te; te--) {
        scanf("%lld%lld%lld", &r, &t, &n);
        remain = 0;
        team = 1;
        for (tol = 0; team * r + remain < n; tol += t) {
            remain += team;
            if (remain >= r) {
               team += remain / r;
               remain %= r;
            }
        }
        printf("%lld\n", tol);
    }
}
