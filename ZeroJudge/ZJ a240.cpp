#include <iostream>
#include <string>
using namespace std;

int main() {
	string s = "0588235294117647";  //¥`¿Ù∏`
	int n, m, i, ans, sum[17] = {0};
	for (i = 1; i <= 16; i++) sum[i] = sum[i-1] + s[i] - '0';
	for (cin >> m; m; m--) {
		cin >> n;
		n--;
		ans = (n / 16) * sum[15] + sum[n % 16];
		cout << s[n % 16] << " " << ans << endl;
	}
}