#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

int main() {
    int n, t, i, a[20];
    for (scanf("%d", &t); t; t--) {
        scanf("%d", &n);
        for (i = 0; i < 4; i++) scanf("%d", &a[i]);
        for (i = 4; i < n; i++) a[i] = a[i-1] + a[i-4];
        sort(a, a+n);
        printf("%d\n", a[n/2]);
    }
}
