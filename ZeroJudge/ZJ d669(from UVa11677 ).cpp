#include <iostream>
using namespace std;


int main()
{
	int h1, h2, m1, m2;
	while (cin >> h1 >> m1 >> h2 >> m2, (h1 || h2 || m1 || m2))
	{
		m1 += h1 * 60;
		m2 += h2 * 60; /* 換成分鐘 */
		m2 -= m1; /* 後面減前面 */
		if (m2 < 0) m2 += 1440; /* 如果是負數 (代表繞過0時0分)，加 1440 分 (一天) */
		cout << m2 << endl;
	}
}