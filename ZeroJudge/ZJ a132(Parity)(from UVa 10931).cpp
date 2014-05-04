#include <iostream>
using namespace std;

int t;

void base(int x) /* 10 進位轉 2 進位 */
{
	if (x > 1) base(x / 2); /* 遞迴，模擬我們手算進位轉換 (餘式定理) */
	if (x % 2) cout << '1', t++;
	else cout << '0';
	return;
}

int main()
{
	int n;
	while (cin >> n, n)
	{
		t = 0;
		cout << "The parity of ";
		base(n);
		cout << " is " << t << " (mod 2)." << endl;
	}
}