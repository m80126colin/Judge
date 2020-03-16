/**
 *  @judge UVa
 *  @id 10313
 *  @name Pay the Price
 * 
 *  @tag Change-making, Range Query
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
const int N = 301;
vector<LL> dp[N];
vector<int> cmd;

void init() {
	for (int i = 0; i < N; i++)
		dp[i] = vector<LL>(i + 1, 0);
	// Change-making
	dp[0][0] = 1;
	for (int c = 1; c < N; c++)
		for (int j = 0; j < N - c; j++)
			for (int i = 0; i < j + 1; i++)
				if (i < j + c)
					dp[j + c][i + 1] += dp[j][i];
	// Prefix Sum
	for (int j = 0; j < N; j++)
		for (int i = 1; i < j + 1; i++)
			dp[j][i] += dp[j][i - 1];
	return ;
}

LL solve() {
	if (cmd.size() == 1)
		return dp[cmd[0]][dp[cmd[0]].size() - 1];
	if (cmd.size() == 2)
		return dp[cmd[0]][min(cmd[0], cmd[1])];
	// cmd.size() == 3
	if (cmd[1] == 0)
		return dp[cmd[0]][min(cmd[0], cmd[2])];
	if (cmd[1] > cmd[0])
		return 0;
	return dp[cmd[0]][min(cmd[0], cmd[2])] - dp[cmd[0]][cmd[1] - 1];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int u;
	string line;
	stringstream ss;
	init();
	while (getline(cin, line)) {
		cmd.clear();
		ss.clear();
		ss << line;
		while (ss >> u)
			cmd.push_back(u);
		cout << solve() << endl;
	}
}