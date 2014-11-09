#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define MAX 110
int n;
int c[MAX][MAX], ct[MAX][MAX], cptr[MAX];
char s[MAX][MAX];

int check() {
	int i, j, k;
	for (i = 0; i < n; i++)
		for (j = i + 1; j < n; j++) {
			if (cptr[i] != cptr[j])
				return 0;
		}
	for (i = 0; i < n; i++)
		for (j = i + 1; j < n; j++) {
			for (k = 0; k < cptr[i]; k++)
				if (c[i][k] != c[j][k])
					return 0;
		}
	return 1;
}

int count(int pos) {
	int i, arr[MAX];
	for (i = 0; i < n; i++)
		arr[i] = ct[i][pos];
	sort(arr, arr + n);
	int mid = arr[n / 2];
	int res = 0;
	for (i = 0; i < n; i++)
		res += abs(arr[i] - mid);
	return res;
}

int main() {
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w+", stdout);
	int t, cnt, i, j;
	for (scanf("%d", &t), cnt = 1; cnt <= t; cnt++) {
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			scanf("%s", s[i]);
		memset(c, 0, sizeof(c));
		memset(ct, 0, sizeof(ct));
		memset(cptr, 0, sizeof(cptr));
		for (i = 0; i < n; i++) {
			int len = strlen(s[i]);
			for (j = 0; j < len; j++) {
				if (cptr[i] > 0 && c[i][cptr[i] - 1] == s[i][j])
					ct[i][cptr[i] - 1]++;
				else {
					c[i][cptr[i]] = s[i][j];
					ct[i][cptr[i]]++;
					cptr[i]++;
				}
			}
		}
		printf("Case #%d: ", cnt);
		if (check()) {
			int ans = 0;
			if (n) {
				for (i = 0; i < cptr[0]; i++)
					ans += count(i);
			}
			printf("%d\n", ans);
		}
		else puts("Fegla Won");
	}
}