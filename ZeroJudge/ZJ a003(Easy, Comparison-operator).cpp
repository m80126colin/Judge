#include <iostream>
using namespace std;

int main() {
	int m, d;
	while (cin >> m >> d) {
		m = ( m * 2 + d) % 3;
		if (m == 2) cout << "¤j¦N" << endl;
		else if (m) cout << "¦N" << endl;
		else cout << "´¶³q" << endl;
	}
}