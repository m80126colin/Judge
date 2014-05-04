#include <iostream>
using namespace std;

int main() {
	int a[77], i;
	a[0] = 1, a[1] = 1, a[2] = 2;
	for (i = 3; i <= 76; i++) a[i] = a[i - 2] + a[i - 3];
	while (cin >> i) cout << a[i] << endl;
}