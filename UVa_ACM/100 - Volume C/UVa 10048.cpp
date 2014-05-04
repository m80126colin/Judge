#include <stdio.h>
#include <string.h>
#include <iostream>
#define MAX 101
#define iMAX 2147483647
using namespace std;

int map[MAX][MAX];
int c, s, q, ctr;

int main() {
	int i, j, k, w;
	for (ctr = 1; scanf("%d%d%d", &c, &s, &q) && (c || s || q); ctr++) {
		for (i = 1; i <= c; i++)
			for (j = 1; j <= c; j++)
				map[i][j] = iMAX;
		for (i = 0; i < s; i++) {
			scanf("%d%d%d", &j, &k, &w);
			map[j][k] = map[k][j] = w;
		}
		for (k = 1; k <= c; k++)
			for (i = 1; i <= c; i++)
				for (j = 1; j <= c; j++)
					map[i][j] = min(map[i][j], max(map[i][k], map[k][j]));
		if (ctr > 1) puts("");
		printf("Case #%d\n", ctr);
		for (i = 0; i < q; i++) {
			scanf("%d%d", &j, &k);
			if (map[j][k] != iMAX) printf("%d\n", map[j][k]);
			else puts("no path");
		}
	}
}