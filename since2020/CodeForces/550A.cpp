/**
 * 	@judge CodeForces
 * 	@id 550A
 * 	@name Two Substrings
 * 
 * 	@tag String manipulation
 */
#include <iostream>
using namespace std;

bool solve(string s) {
	int len = s.size();
	int ABBA = -1;
	int BAAB = -1;
	for (int i = 0; i < len - 1; i++) {
		if (ABBA == -1 && s[i] == 'A' && s[i + 1] == 'B')
			ABBA = i;
		if (BAAB == -1 && s[i] == 'B' && s[i + 1] == 'A')
			BAAB = i;
		if (ABBA >= 0 && i - ABBA > 1 && s[i] == 'B' && s[i + 1] == 'A')
			return true;
		if (BAAB >= 0 && i - BAAB > 1 && s[i] == 'A' && s[i + 1] == 'B')
			return true;
	}
	return false;
}

int main() {
	string str;
	while (cin >> str) {
		if (solve(str))
			cout << "YES" <<endl;
		else
			cout << "NO" << endl;
	}
}