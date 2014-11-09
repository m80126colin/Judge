#include <cstdio>
#include <iostream>
#include <string>
#include <map>
using namespace std;

int n, cnt;
string str, ans;
map<string, int> code;
map<string, int>::iterator it;

int main() {
	while (cin >> n >> str) {
		code.clear();
		cnt = 0;
		ans = "";
		for (int i = 0; i < str.size() - n; i++)
			code[str.substr(i, n)]++;
		for (it = code.begin(); it != code.end(); it++) {
			if (cnt < it->second) {
				ans = it->first;
				cnt = it->second;
			}
		}
		cout << ans << endl;
	}
}