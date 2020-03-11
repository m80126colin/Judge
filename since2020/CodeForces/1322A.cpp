/**
 *  @judge CodeForces
 *  @id 1322A
 *  @name Unusual Competitions
 *  @contest Codeforces Round #626
 * 
 *  @tag Greedy, Parentheses Matching
 */
#include <iostream>
#include <vector>
using namespace std;

#define MAX 1000010

int n, L[MAX], R[MAX];
string str;

bool check(int Lp, int Rp) {
	for (int i = Lp + 1; i <= Rp; i++)
		if (L[i] < R[i])
			return false;
	return true;
}

int solve() {
	L[0] = R[0] = 0;
	for (int i = 0; i < n; i++) {
		L[i + 1] = L[i] + (str[i] == '(');
		R[i + 1] = R[i] + (str[i] == ')');
	}
	if (L[n] != R[n])
		return -1;
	int ans = 0, left = 0;
	for (int i = 1; i <= n; i++) {
		if (L[i] == R[i]) {
			if (check(left, i) == false)
				ans += i - left;
			left = i;
		}
	}
	if (left != n && check(left, n) == false)
		ans += n - left;
	return ans;
}

int main() {
	cin >> n >> str;
	cout << solve() << endl;
}