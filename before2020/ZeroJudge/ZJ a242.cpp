#include <iostream>
#include <algorithm>
#include <cctype>
#define MAX 100010
using namespace std;

struct arr{
	int a, x;
}cnt[MAX];
int n, m;
int all, sum, tmp, lvl;

inline void input(int &d) {
	char ch;
	while (!isdigit(ch = getchar())) ;
	d = 0;
	do {
		d = d * 10 + ch - '0';
	} while (isdigit(ch = getchar()));
}

bool cmp(arr left, arr right) {
	return left.x < right.x;
}

int main() {
	int i, j, ans;
	for (cin >> m; m; m--) {
		cin >> n;
		sum = 0;
		memset(cnt, 0, sizeof(cnt));
		for (i = 0; i < n; i++) {
			input(cnt[i].a);
			input(cnt[i].x);
			cnt[i].x /= cnt[i].a;
			sum += cnt[i].a;
		}
		sort(cnt, cnt + n, cmp);
		lvl = sum / 2 + 1;
		for (j = tmp = 0; j < n; j++) {
			if (tmp + cnt[j].a >= lvl) break;
			tmp += cnt[j].a;
		}
		ans = 0;
		for (i = 0; i < n; i++) ans += abs(cnt[i].a * (cnt[j].x - cnt[i].x));
		cout << ans << endl;
	}
}