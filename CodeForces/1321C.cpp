/**
 *  CodeForces 1321C, Round #625 div.2 C
 *  Remove Adjacent
 * 
 *  Tags: Ad-hoc, String Manipulation
 */
#include <iostream>
using namespace std;

int L;
string s;

int solve() {
	L = s.size();
	for (char ch = 'z'; ch >= 'a'; ch--) {
		string tmp = "";
		for (int i = 0; i < s.size(); i++)
			if (!(i > 0 && s[i] == ch && tmp[tmp.size() - 1] + 1 == s[i]))
				tmp += s[i];
		s = tmp;
		tmp = "";
		for (int i = s.size() - 1; i >= 0; i--)
			if (!(i + 1 < s.size() && s[i] == ch && s[i] == tmp[0] + 1))
				tmp = s[i] + tmp;
		s = tmp;
	}
	return L - s.size();
}

int main() {
	int n;
	cin >> n >> s;
	cout << solve() << endl;
}