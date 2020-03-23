/**
 *  @judge UVa
 *  @id 11456
 *  @name Trainsorting
 * 
 *  @tag Longest Increasing Subsequence
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

int n;
vector<int> arr, lis, lds;

int solve() {
	lis = vector<int>(n, 1);
	lds = vector<int>(n, 1);
	for (int i = n - 1; i >= 0; i--)
		for (int j = i + 1; j < n; j++)
			if (arr[i] < arr[j])
				lds[i] = max(lds[i], lds[j] + 1);
			else if (arr[i] > arr[j])
				lis[i] = max(lis[i], lis[j] + 1);
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(ans, lis[i] + lds[i] - 1);
	lis.clear();
	lds.clear();
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	for (cin >> t; t; t--) {
		cin >> n;
		arr = vector<int>(n);
		for (auto && x: arr)
			cin >> x;
		cout << solve() << endl;
		arr.clear();
	}
}