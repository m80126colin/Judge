/**
 *  @judge CodeForces
 *  @id 1305D
 *  @name Kuroni and the Celebration
 *  @contest Ozon Tech Challenge 2020
 * 
 *  @tag Ad-hoc, Simulation
 */
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

#define MAX 1010

int n, remain[MAX];
vector<int> edges[MAX], leaves;

void del_node(int x) {
	int y;
	for (int i = 0; i < edges[x].size(); i++) {
		y = edges[x][i];
		if (remain[y]) {
			remain[x]--;
			remain[y]--;
			if (remain[y] == 1)
				leaves.push_back(y);
			return ;
		}
	}
	return ;
}

int solve() {
	leaves.clear();
	for (int i = 1; i <= n; i++) {
		remain[i] = edges[i].size();
		if (remain[i] == 1)
			leaves.push_back(i);
	}
	int u, v, ans;
	while (leaves.size() > 1) {
		u = leaves[0];
		v = leaves[1];
		leaves.erase(leaves.begin());
		leaves.erase(leaves.begin());
		printf("? %d %d\n", u, v);
		fflush(stdout);
		cin >> ans;
		if (ans == u || ans == v)
			return ans;
		del_node(u);
		del_node(v);
	}
	return leaves[0];
}

int main() {
	int u, v;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	int ans = solve();
	printf("! %d\n", ans);
}