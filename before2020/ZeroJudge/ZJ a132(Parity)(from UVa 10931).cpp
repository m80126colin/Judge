/**
 *  @judge ZeroJudge
 *  @id a132
 *  @tag Parity
 */
#include <iostream>
using namespace std;

int t;

void base(int x) /* 10 �i���� 2 �i�� */
{
	if (x > 1) base(x / 2); /* ���j�A�����ڭ̤��i���ഫ (�l���w�z) */
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