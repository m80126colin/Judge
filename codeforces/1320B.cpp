/**
 *  CodeForces 1320B, Round #625 div.2 D
 *  Navigation System
 * 
 *  Tags: BFS
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 200010

int n, m, k, path[MAX], dist[MAX], ox[MAX], inq[MAX], vist[MAX];
vector<int> edge[MAX], rev[MAX];

void bfs() {
	queue<int> Q;
	for (int i = 1; i <= n; i++)
		inq[i] = vist[i] = 0;
	Q.push(path[k - 1]);
	inq[path[k - 1]] = 1;
	while (!Q.empty()) {
		int node = Q.front();
		Q.pop();
		vist[node] = 1;
		inq[node] = 0;
		for (int j = 0; j < rev[node].size(); j++) {
			int end = rev[node][j];
			if (!vist[end] && dist[end] == 0) {
				dist[end] = dist[node] + 1;
				if (!inq[end]) {
					Q.push(end);
					inq[end] = 1;
				}
			}
		}
	}
}

void solve() {
	for (int i = 1; i <= n; i++)
		dist[i] = ox[i] = 0;
	bfs();
	for (int i = 1; i <= n; i++) {
		int count = 0;
		for (int j = 0; j < edge[i].size(); j++)
			if (dist[edge[i][j]] + 1 == dist[i])
				count++;
		if (count > 1)
			ox[i] = 1;
	}
	int ans = 0, d = 0;
	for (int i = 0; i + 1 < k; i++) {
		if (dist[path[i]] != dist[path[i + 1]] + 1)
			ans++;
		else if (ox[path[i]]) {
			ans++;
			d++;
		}
	}
	cout << ans - d << " " << ans << endl;
}

int main() {
	int u, v;
	cin >> n >> m;
	for (int j = 0; j < m; j++) {
		cin >> u >> v;
		edge[u].push_back(v);
		rev[v].push_back(u);
	}
	cin >> k;
	for (int i = 0; i < k; i++)
		cin >> path[i];
	solve();
}