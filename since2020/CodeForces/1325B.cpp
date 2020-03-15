/**
 *  @judge CodeForces
 *  @id 1325B
 *  @name CopyCopyCopyCopyCopy
 *  @contest Codeforces Round #628
 * 
 *  @tag Distinct Item
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

int n;
set<int> S;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t, a;
	for (cin >> t; t; t--) {
		cin >> n;
		S.clear();
		for (int i = 0; i < n; i++) {
			cin >> a;
			S.insert(a);
		}
		cout << S.size() << endl;
		S.clear();
	}
}