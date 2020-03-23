/**
 *  @judge CodeForces
 * 	@id 1326B
 *  @name Maximums
 * 
 *  @tag Simple Math, Simulation
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

int n;
vector<LL> arr;

void solve() {
	LL ans = 0;
	for (const auto &x : arr) {
		cout << x + ans << " ";
		if (x > 0)
			ans += x;
	}
	cout << endl;
}

int main() {
	cin >> n;
	arr = vector<LL>(n);
	for (auto && x : arr)
		cin >> x;
	solve();
}