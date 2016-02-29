#include <string.h>
#include <iostream>
using namespace std;

int n, m, a[200], b[20000][2];

int re(int x, int y) {
	int i, j;
	for (i = 1; i <= m; i++) {
		for (j = 0; j <= 1; j++) {
			if (x == b[i][j] && !a[b[i][!j]]) {
				if (y == 1) {
					a[b[i][!j]] = 2;
					re(b[i][!j], 2);
				}
				else {
					a[b[i][!j]] = 1;
					re(b[i][!j], 1);
				}
			}
		}
	}
	return 0;
}

int main() {
	bool ox;
	int i, j;
	while (cin >> n && n) {
		memset(a, 0, 4 * n);
		cin >> m;
		for (i = 1; i <= m; i++) cin >> b[i][0] >> b[i][1];
		a[0] = 1;
		re(0, 1);
		ox = 1;
		for (i = 0; i < n; i++) {
			for (j = 1; j <= m; j++) {
				if (i == b[j][0] && a[b[j][1]] == a[i]) {
					ox = 0;
					break;
				}
				if (i == b[j][1] && a[b[j][0]] == a[i]) {
					ox = 0;
					break;
				}
			}
		}
		if (ox) cout << "BICOLORABLE.\n";
		else cout << "NOT BICOLORABLE.\n";
	}
}