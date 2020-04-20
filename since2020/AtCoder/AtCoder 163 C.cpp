/**
 *  @judge AtCoder
 *  @id abc163_c
 *  @name management
 *  @contest AtCoder Beginner Contest 163
 * 
 *  @tag Ad-hoc, Counting
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

int n;
vector<int> a;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	while (cin >> n) {
		a = vector<int>(n + 1, 0);
		for (int i = 0; i < n - 1; i++) {
			cin >> t;
			a[t]++;
		}
		for (int i = 1; i <= n; i++)
			cout << a[i] << endl;
		a.clear();
	}
}