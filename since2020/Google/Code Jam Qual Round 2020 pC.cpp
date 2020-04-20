/**
 *  @judge Google Code Jam
 *  @id Qualification Round 2020 pC
 *  @name Parenting Partnering Returns
 *  @contest Google Code Jam Qualification Round 2020
 * 
 *  @tag Greedy, Monotonicity
 */
#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> seg;
string ans;

string solve() {
	if (n == 2)
		return "CJ";
	int C, J;
	string res(n, 'C');
	vector<int> index(n);
	for (int i = 0; i < n; i++)
		index[i] = i;
	sort(index.begin(), index.end(), [](int L, int R) {
		if (seg[L].first != seg[R].first)
			return seg[L].first < seg[R].first;
		return seg[L].second < seg[R].second;
	});
	C = J = 0;
	for (auto &idx : index) {
		int L = seg[idx].first;
		int R = seg[idx].second;
		if (C <= L)
			C = R;
		else if (J <= L) {
			res[idx] = 'J';
			J = R;
		}
		else
			return "IMPOSSIBLE";
	}
	return res;
}

int main() {
	int t, s, e;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n;
		seg.clear();
		for (int j = 0; j < n; j++) {
			cin >> s >> e;
			seg.emplace_back(s, e);
		}
		cout << "Case #" << i << ": " << solve() << endl;
	}
}