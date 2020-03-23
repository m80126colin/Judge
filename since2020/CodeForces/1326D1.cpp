/**
 *  @judge CodeForces
 * 	@id 1326D1
 *  @name Prefix-Suffix Palindrome (Easy version)
 * 
 *  @tag Palindrome
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

const int MAX = 5010;

string s;
int prep[MAX], postp[MAX];

bool isp(const string &str) {
	int M = str.size() / 2;
	for (int i = 0; i < M; i++)
		if (str[M - i - 1] != str[M + i + str.size() % 2])
			return false;
	return true;
}

string presuf(string str) {
	string tmp;
	for (int i = str.size(); i; i--) {
		tmp = str.substr(0, i);
		if (isp(tmp))
			return tmp;
		tmp = str.substr(str.size() - i);
		if (isp(tmp))
			return tmp;
	}
	return "";
}

string solve() {
	int M = s.size() / 2, k;
	for (k = 0; k < M; k++)
		if (s[k] != s[s.size() - k - 1])
			break ;
	return s.substr(0, k) + presuf(s.substr(k, s.size() - k - k)) + s.substr(s.size() - k);
}

int main() {
	int t;
	for (cin >> t; t; t--) {
		cin >> s;
		cout << solve() << endl;
	}
}