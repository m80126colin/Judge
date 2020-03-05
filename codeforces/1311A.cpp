/**
	CodeForces Round #624 div.3
*/
#include <iostream>
using namespace std;

int solve(int a, int b) {
	if (a == b)
		return 0;
	if (a > b) {
		if (a % 2 == b % 2)
			return 1;
		else
			return 2;
	}
	if (a % 2 != b % 2)
		return 1;
	return 2;
}

int main() {
	int t, a, b;
	for (cin >> t; t; t--) {
		cin >> a >> b;
		cout << solve(a, b) << endl;
	}
}