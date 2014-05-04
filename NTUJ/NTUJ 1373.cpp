#include <stdio.h>
#include <string.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#define MAX 40000
using namespace std;

struct circle{
       int x, y;
}c[MAX];
int e, p, n;
double r2;

bool isinter() {
     int i, j;
     for(i = 0; i < n; i++) {
           for (j = i + 1; j < n; j++) {
               if ((c[j].x - c[i].x) * (c[j].x - c[i].x) > 4 * r2) break;
               if ((c[j].x - c[i].x) * (c[j].x - c[i].x) + (c[j].y - c[i].y) * (c[j].y - c[i].y) <= 4 * r2) return 1;
           }
     }
     return 0;
}

bool cmp(circle a, circle b) {
     if (a.x != b.x) return a.x < b.x;
     return a.y < b.y;
}

int main() {
    int i;
    while (scanf("%d", &n), n) {
          for (i = 0; i < n; i++) scanf("%d%d", &c[i].x, &c[i].y);
          sort(c, c + n, cmp);
          scanf("%d%d", &e, &p);
          r2 = (double) 1000 * p / e;
          if (isinter()) puts("NO");
          else puts("YES");
    }
}
