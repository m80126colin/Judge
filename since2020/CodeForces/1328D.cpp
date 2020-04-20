/**
 *  @judge CodeForces
 *  @id 1328D
 *  @name Carousel
 *  @contest Codeforces Round #629 (Div. 3)
 * 
 *  @tag Greedy, Cycle Detecting
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

int n;
vector<int> arr;

bool isSame(const vector<int> &xs) {
	for (int i = 0; i < xs.size() - 1; i++)
		if (xs[i] != xs[i + 1])
			return false;
	return true;
}

int oddPos(const vector<int> &xs) {
	for (int i = 0; i < xs.size(); i++)
		if (xs[i] == xs[(i + 1) % xs.size()])
			return i;
	return -1;
}

auto solve() {
	vector<int> res(n, 1);
	if (isSame(arr))
		return make_tuple(1, res);
	for (int i = 1; i < res.size(); i += 2)
		res[i] = 2;
	if (n % 2 == 0)
		return make_tuple(2, res);
	int pos = oddPos(arr);
	if (pos == -1) {
		res[res.size() - 1] = 3;
		return make_tuple(3, res);
	}
	vector<int> temp(res.begin(), res.end() - pos - 1);
	res = vector<int>(res.end() - pos - 1, res.end());
	res.insert(res.end(), temp.begin(), temp.end());
	return make_tuple(2, res);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t, T;
	vector<int> res;
	for (cin >> t; t; t--) {
		cin >> n;
		arr = vector<int>(n);
		for (auto &&x : arr)
			cin >> x;
		tie(T, res) = solve();
		cout << T << endl;
		for (const auto &x : res)
			cout << x << " ";
		cout << endl;
		arr.clear();
	}
}