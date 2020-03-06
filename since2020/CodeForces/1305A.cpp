/**
 *  CodeForces 1305A, Ozon Tech Challenge 2020
 *  Kuroni and the Gifts
 * 
 *  Tags: Sorting
 */
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 1010

int n, a[MAX], b[MAX];

void printArray(int* arr, int len) {
	cout << arr[0];
	for (int i = 1; i < len; i++)
		cout << " " << arr[i];
	cout << endl;
	return ;
}

void solve() {
	sort(a, a + n);
	sort(b, b + n);
	printArray(a, n);
	printArray(b, n);
	return;
}

int main() {
	int t;
	for (cin >> t; t; t--) {
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n; i++)
			cin >> b[i];
		solve();
	}
}