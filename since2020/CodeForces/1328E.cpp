/**
 *  @judge CodeForces
 *  @id 1328E
 *  @name Tree Queries
 *  @contest Codeforces Round #629 (Div. 3)
 * 
 *  @tag Depth First Search
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

int n, m, stamp;
vector<int> parent, query;
vector<vector<int>> edges;
vector<tuple<int, int, int>> info;

void dfs(int u, int p = 0, int d = 0) {
	parent[u] = p;
	get<0>(info[u]) = d;
	get<1>(info[u]) = stamp++;
	for (const auto &v : edges[u]) {
		if (v == p)
			continue;
		dfs(v, u, d + 1);
	}
	get<2>(info[u]) = stamp++;
}

bool solve() {
	int u = query[0];
	for (const auto &v : query)
		if (get<0>(info[u]) < get<0>(info[v]))
			u = v;
	for (const auto &v : query)
		if (get<1>(info[u]) < get<1>(info[v]) || get<2>(info[v]) < get<2>(info[u]))
			return false;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int u, v, k;
	cin >> n >> m;
	edges = vector<vector<int>>(n + 1);
	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	parent = vector<int>(n + 1, 0);
	info   = vector<tuple<int,int,int>>(n + 1, make_tuple(0, 0, 0));
	stamp  = 1;
	dfs(1, 1);
	for (int j = 0; j < m; j++) {
		cin >> k;
		query = vector<int>(k);
		for (auto &&q : query) {
			cin >> q;
			q = parent[q];
		}
		cout << (solve() ? "YES" : "NO") << endl;
		query.clear();
	}
	parent.clear();
	info.clear();
	edges.clear();
}