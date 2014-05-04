#include <string>
#include <stdio.h>
#include <iostream>
using namespace std;

struct page
{
	int relat;
	string name;
}p[10];

int main()
{
	int n, t, i, mx;
	for (cin >> n, t = 1; t <= n; t++)
	{
		mx = 0;
		for (i = 0; i < 10; i++) cin >> p[i].name >> p[i].relat, mx = max(mx, p[i].relat); /* 紀錄最大值 */
		printf("Case #%d:\n", t);
		for (i = 0; i < 10; i++)
		{
			if (p[i].relat == mx) cout << p[i].name << endl; /* 將相同最大值照順序輸出 */
		}
	}
}