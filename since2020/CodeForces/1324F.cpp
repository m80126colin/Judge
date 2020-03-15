/**
 *  @judge CodeForces
 *  @id 1324F
 *  @name Maximum White Subtree
 *  @contest Codeforces Round #627
 * 
 *  @tag Tree Dynamic Programming
 */
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a, dp, ans;
vector<vector<int>> edges;

// dp: the maximum when containing node and its subtrees
void dfs(int node, int parent = -1) {
	dp[node] = a[node] ? 1: -1;
	for (const auto &v : edges[node]) {
		if (v == parent)
			continue ;
		dfs(v, node);
		dp[node] += max(0, dp[v]);
	}
	return ;
}

// rerooting
void dfs2(int node, int parent = -1) {
	ans[node] = dp[node];
	for (const auto &v : edges[node]) {
		if (v == parent)
			continue ;
		dp[node] -= max(0, dp[v]);
		dp[v] += max(0, dp[node]);
		dfs2(v, node);
		dp[v] -= max(0, dp[node]);
		dp[node] += max(0, dp[v]);
	}
}

int main() {
	cin >> n;
	a = dp = ans = vector<int>(n);
	edges = vector<vector<int>>(n);
	for (auto && x : a)
		cin >> x;
	int u, v;
	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		edges[u - 1].push_back(v - 1);
		edges[v - 1].push_back(u - 1);
	}
	dfs(0);
	dfs2(0);
	for (const auto &x : ans)
		cout << x << " ";
	cout << endl;
}