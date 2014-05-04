#include <iostream>
using namespace std;

int main () {
	int n, m, ans, tmp;
	for (cin >> m; m; m--) {
		ans = 0;
		for (cin >> n; n; n /= 5)
			for (tmp = n; tmp; tmp /= 2)
				ans++;
		cout << ans - 1 << endl;
	}
}