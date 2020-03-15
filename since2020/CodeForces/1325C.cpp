/**
 *  @judge CodeForces
 *  @id 1325C
 *  @name Ehab and Path-etic MEXs
 *  @contest Codeforces Round #628
 * 
 *  @tag Greedy, Graph Theory
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
int n;
vector<int> cnt, label;
vector<pair<int, int>> edges;

void solve() {
	int u, v;
	int L = 0;
	for (int i = 0; i < n - 1; i++) {
		tie(u, v) = edges[i];
		if (cnt[u] == 1) {
			label[i] = L;
			L++;
		}
		else if (cnt[v] == 1) {
			label[i] = L;
			L++;
		}
	}
	for (int i = 0; i < n - 1; i++) {
		tie(u, v) = edges[i];
		if (cnt[u] != 1 && cnt[v] != 1) {
			label[i] = L;
			L++;
		}
	}
	return ;
}

int main() {
	int u, v;
	cin >> n;
	cnt = vector<int>(n, 0);
	label = vector<int>(n - 1, -1);
	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		edges.emplace_back(u - 1, v - 1);
		cnt[u - 1]++;
		cnt[v - 1]++;
	}
	solve();
	for (const auto &x : label)
		cout << x << endl;
	cnt.clear();
	label.clear();
}