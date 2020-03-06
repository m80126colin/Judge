/**
 *  CodeForces 1320A, Round #625 div.2 B
 *  Journey Planning
 * 
 *  Tags: Math, Grouping
 */
#include <iostream>
#include <map>
using namespace std;

#define MAX 200010

int n;
int b[MAX];

map<int, long long> S;

long long solve() {
	S.clear();
	long long df, ans = 0;
	for (int i = 0; i < n; i++) {
		df = b[i] - i;
		S[df] += (long long)b[i];
	}
	map<int, long long>::iterator it;
	for (it = S.begin(); it != S.end(); it++)
		ans = max(ans, it->second);
	return ans;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> b[i];

	cout << solve() << endl;
}