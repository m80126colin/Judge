#include <stdio.h>
#include <ctype.h>
#include <string>
#include <iostream>
using namespace std;

int main() {
	int i, ctr = 1;
	string spk[6] = {"HELLO", "HOLA", "HALLO", "BONJOUR", "CIAO", "ZDRAVSTVUJTE"};
	string lan[6] = {"ENGLISH", "SPANISH", "GERMAN", "FRENCH", "ITALIAN", "RUSSIAN"};
	string s;
	while (cin >> s) {
		if (s == "#") break;
		cout << "Case " << ctr << ": ";
		for (i = 0; i < s.size(); i++)
			if (isalpha(s[i])) s[i] = toupper(s[i]);
		for (i = 0; i < 6; i++) {
			if (s == spk[i]) {
				cout << lan[i] << endl;
				break;
			}
		}
		if (i == 6) cout << "UNKNOWN" << endl;
		ctr++;
	}
}