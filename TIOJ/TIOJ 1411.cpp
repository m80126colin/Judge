#include <stdio.h>

int n[1000001], nn;
int maxn[2000001];

int max(int a, int b) {
    return (a>b)?a:b;
}

int main() {
    int i, tmp;
    while (scanf("%d", &nn)!=EOF) {
          n[0] = 0;
          for (i = 0; i < 2 * nn; i++) maxn[i - nn + 1000000] = 0;
          for (i = 1; i <= nn; i++) {
              scanf("%d", &tmp);
              n[i] = n[i-1] + (tmp > 0) - (tmp < 0);
              maxn[n[i]+1000000] = max(maxn[n[i]+1000000], i);
          }
          tmp = 0;
          for (i = nn; i >= 0; i--) tmp = max(maxn[n[i]+1000000] - i, tmp);
          printf("%d\n", tmp);
    }
} 
