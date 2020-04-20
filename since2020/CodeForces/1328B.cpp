/**
 *  @judge CodeForces
 *  @id 1328B
 *  @name K-th Beautiful String
 *  @contest Codeforces Round #629 (Div. 3)
 * 
 *  @tag Combination & Permutaion
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
const int N = 100010;
vector<LL> triangular;
LL n, k;

void init() {
	triangular = vector<LL>(N, 0);
	for (int i = 1; i < N; i++)
		triangular[i] = triangular[i - 1] + i;
}

string solve() {
	int pos, b1, b2;
	string ans(n, 'a');
	pos = lower_bound(triangular.begin(), triangular.end(), k) - triangular.begin();
	b1 = n - pos - 1;
	b2 = b1 + 1 + (triangular[pos] - k);
	ans[b1] = ans[b2] = 'b';
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	init();
	for (cin >> t; t; t--) {
		cin >> n >> k;
		cout << solve() << endl;
	}
}