#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

char mon[13][20] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November" , "December"};
int day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct DD
{
	char mm[20];
	int d, m, y, tot;
	void input()
	{
		int i;
		scanf("%s%d,%d", mm, &d, &y);
		for (i = 1; i <= 12; i++)
			if (strcmp(mm, mon[i]) == 0)
			{
				m = i;
				break;
			}
		tot = d;
		for (i = 1; i < m && i <= 12; i++)
			tot += day[i] + (i == 2) * isleap();
	}
	bool operator < (const DD &D) const
	{
		if (y != D.y) return y < D.y;
		if (m != D.m) return m < D.m;
		return d <= D.d;
	}
	int isleap()
	{
		return !(y % 400) || (y % 100 && !(y % 4));
	}
}d1, d2;

int leap(int y)
{
	return y / 400 - y / 100 + y / 4;
}

int sol()
{
	int ans = leap(d2.y - 1) - leap(d1.y - 1);
	if (d2.isleap() && d2.tot >= 60) ans++;
	if (d1.isleap() && d1.tot > 60) ans--;
	return ans;
}

int main()
{
	int t, cnt;
	for (scanf("%d", &t), cnt = 1; cnt <= t; cnt++)
	{
		d1.input();
		d2.input();
		if (d2 < d1) swap(d1, d2);
		printf("Case %d: %d\n", cnt, sol());
	}
}