/**
	CodeForces Round #624 div.3
*/
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 200010

int n, v[MAX], pos[MAX], mp[MAX];
long long bit[MAX], node[MAX], x[MAX];

void update(long long *tree, int idx, long long d) {
	for (int i = idx + 1; i <= n; i += i & (-i)) {
		tree[i] += d;
	}
}

long long sum(long long *tree, int idx) {
	long long res = 0;
	for (int i = idx + 1; i; i -= i & (-i)) {
		res += tree[i];
	}
	return res;
}

bool poscmp(int L, int R) {
	if (x[L] != x[R])
		return x[L] < x[R];
	return v[L] < v[R];
}

bool cmp(int L, int R) {
	if (v[L] != v[R])
		return v[L] < v[R];
	return x[L] < x[R];
}

long long solve() {
	long long ans = 0;
	for (int i = 0; i <= n; i++) {
		pos[i] = i;
		bit[i] = node[i] = 0;
	}
	// indexed position
	sort(pos, pos + n, &poscmp);
	for (int i = 0; i < n; i++) {
		mp[pos[i]] = i;
	}
	// sort by velocity
	sort(pos, pos + n, &cmp);
	for (int i = 0; i < n; i++) {
		int p = mp[pos[i]];
		ans += sum(node, p) * x[pos[i]] - sum(bit, p);
		update(bit, p, x[pos[i]]);
		update(node, p, 1);
	}
	return ans;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> x[i];
	for (int i = 0; i < n; i++)
		cin >> v[i];
	cout << solve() << endl;
}