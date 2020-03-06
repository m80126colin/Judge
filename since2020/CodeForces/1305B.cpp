/**
 *  @judge CodeForces
 *  @id 1305B
 *  @name Kuroni and Simple Strings
 *  @contest Ozon Tech Challenge 2020
 * 
 *  @tag String Manipulation, Greedy
 */
#include <iostream>
using namespace std;

#define MAX 1010

string s;
int LL[MAX], RR[MAX];

int check(char A, char B) {
	if (A == B)
		return 1;
	return 0;
}

void solve() {
	LL[0] = check(s[0], '(');
	RR[s.size() - 1] = check(s[s.size() - 1], ')');
	for (int i = 1; i < s.size(); i++) {
		int j = s.size() - 1 - i;
		LL[i] = LL[i - 1] + check(s[i], '(');
		RR[j] = RR[j + 1] + check(s[j], ')');
	}
	for (int i = 0; i < s.size() - 1; i++) {
		if (LL[i] > 0 && LL[i] == RR[i + 1]) {
			cout << '1' << endl;
			cout << LL[i] * 2 << endl;
			int count = 0;
			for (int j = 0; j <= i; j++) {
				if (s[j] == '(') {
					if (count)
						cout << " ";
					cout << j + 1;
					count++;
				}
			}
			for (int j = i + 1; j < s.size(); j++) {
				if (s[j] == ')')
					cout << " " << j + 1;
			}
			cout << endl;
			return ;
		}
	}
	cout << '0' << endl;
	return ;
}

int main() {
	cin >> s;
	solve();
}