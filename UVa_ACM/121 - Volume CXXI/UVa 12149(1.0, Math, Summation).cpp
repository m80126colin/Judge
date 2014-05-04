#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
	int n[101], i;
	n[0] = 0;
	for (i = 1; i <= 100; i++) n[i] = n[i - 1] + i * i;
	while (cin >> i, i) {
		cout << n[i] << endl;
	}
}