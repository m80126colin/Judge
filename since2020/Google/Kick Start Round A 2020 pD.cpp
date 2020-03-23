/**
 *  @judge Kick Start
 *  @id Round A 2020 pD
 *  @contest Google Kick Start Round A 2020
 *  @tag Trie, Tree Dynamic Programming
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
int n, k, ans;
vector<string> ss;
vector< tuple<string, int, vector<int>> > tree;

int instree(string s, int root = 0) {
	string prefix = get<0>(tree[root]);
	if (s == prefix) {
		get<1>(tree[root])++;
		return root;
	}
	for (int i = 0; i < prefix.size(); i++) {
		if (i >= s.size() || s[i] != prefix[i]) {
			string sub = prefix.substr(0, i);
			string sup = prefix.substr(i);
			tree.emplace_back(sub, 0, vector<int>());
			int index = tree.size() - 1;
			get<0>(tree[root]) = sup;
			get<2>(tree[index]).push_back(root);
			return instree(s, index);
		}
	}
	for (auto && nxt : get<2>(tree[root])) {
		if (get<0>(tree[nxt])[0] == s[prefix.size()]) {
			nxt = instree(s.substr(prefix.size()), nxt);
			return root;
		}
	}
	string after = s.substr(prefix.size());
	tree.emplace_back(after, 1, vector<int>());
	get<2>(tree[root]).push_back(tree.size() - 1);
	return root;
}

int traversal(int len, int root = 0) {
	int L = len + get<0>(tree[root]).size();
	int tot = get<1>(tree[root]);
	for (const auto & nxt : get<2>(tree[root]))
		tot += traversal(L, nxt);
	ans += (tot / k) * (L - (get<2>(tree[root]).size() == 0));
	return tot % k;
}

int solve() {
	tree.emplace_back("", 0, vector<int>());
	for (const auto& s : ss)
		instree(s + "$");
	ans = 0;
	traversal(0);
	tree.clear();
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n >> k;
		ss = vector<string>(n);
		for (auto && s : ss)
			cin >> s;
		cout << "Case #" << i << ": " << solve() << endl;
		ss.clear();
	}
}