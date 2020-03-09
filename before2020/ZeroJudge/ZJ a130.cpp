/**
 *  @judge ZeroJudge
 *  @id a130
 *  @source UVa 12015
 */
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
		for (i = 0; i < 10; i++) cin >> p[i].name >> p[i].relat, mx = max(mx, p[i].relat); /* �����̤j�� */
		printf("Case #%d:\n", t);
		for (i = 0; i < 10; i++)
		{
			if (p[i].relat == mx) cout << p[i].name << endl; /* �N�ۦP�̤j�ȷӶ��ǿ�X */
		}
	}
}