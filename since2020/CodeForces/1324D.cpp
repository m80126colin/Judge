/**
 *  @judge CodeForces
 *  @id 1324D
 *  @name Pair of Topics
 *  @contest Codeforces Round #627
 * 
 *  @tag Sortings, Binary Search, Two Pointers
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

int n;
vector<int> arr;

LL solve() {
	LL ans = 0;
	sort(arr.begin(), arr.end());
	for (int L = 0, R = n - 1; L < R; R--) {
		while (L < R && arr[L] + arr[R] <= 0)
			L++;
		ans += R - L;
	}
	return ans;
}

int main() {
	int b;
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin >> n;
	arr = vector<int>(n, 0);
	for (auto && v : arr)
		cin >> v;
	for (auto && v : arr) {
		cin >> b;
		v -= b;
	}
	cout << solve() << endl;
}