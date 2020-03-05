/**
	CodeForces Round #624 div.3
*/
#include <iostream>
#include <algorithm>
using namespace std;

#define PMAX 200010
#define MAX 26

int res[MAX], p[PMAX], n, m;
string str;

int solve() {
	int j = 0;
	sort(p, p + m);
	for (int i = 0; i < n; i++) {
		while (j < m && p[j] - 1 < i)
			j++;
		// cout << "j: " << j << ", i: " << str[i] - 'a' << endl;
		res[str[i] - 'a'] += (m - j + 1);
	}
}

int main() {
	int t;
	for (cin >> t; t; t--) {
		cin >> n >> m >> str;
		for (int j = 0; j < m; j++)
			cin >> p[j];
		for (int k = 0; k < MAX; k++)
			res[k] = 0;
		solve();
		for (int k = 0; k < MAX - 1; k++)
			cout << res[k] << " ";
		cout << res[MAX - 1] << endl;
	}
}