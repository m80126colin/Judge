/**
 *  @judge AtCoder
 *  @id abc163_b
 *  @name Homework
 *  @contest AtCoder Beginner Contest 163
 * 
 *  @tag Ad-hoc, Math
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

int n, m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	while (cin >> n >> m) {
		for (int i = 0; i < m; i++) {
			cin >> t;
			n -= t;
		}
		cout << max(-1, n) << endl;
	}
}