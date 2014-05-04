#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

char sday[8][20] = {"", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
char mon[13][20] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November" , "December"};
int day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct Date
{
	int m, d, y;
	int input()
	{
		scanf("%d%d%d", &m, &d, &y);
		return m || d || y;
	}
	bool operator < (const Date &D) const
	{
		if (y != D.y) return y < D.y;
		if (m != D.m) return m < D.m;
		return d < D.d;
	}
}D;

const int c1 = 6, c3 = 3;
const Date d1 = {1, 1, 1}, d2 = {9, 2, 1752}, d3 = {9, 14, 1752};

int isleap(const Date&);

int valid(const Date &date)
{
	if (date.d <= 0 || date.m <= 0 || date.m >= 13 || date.y <= 0) return 0;
	if (d2 < date && date < d3) return 0;
	if (date.d > day[date.m] + (date.m == 2) * isleap(date)) return 0;
	return 1;
}

int isleap(const Date& date)
{
	if (date < d3)
		return !(date.y % 4);
	else
		return !(date.y % 400) || (date.y % 100 && !(date.y % 4));
}

int leap(const Date& date)
{
	int tmp = date.y - 1;
	if (date < d3)
		return tmp / 4;
	else
		return tmp / 4 - tmp / 100 + tmp / 400;
}

int days(const Date& date)
{
	int tmp = date.y - 1, res;
	res = tmp * 365 + leap(date);
	for (int i = 1; i < date.m; i++)
		res += (i == 2) * isleap(date) + day[i];
	res += date.d;
	return res;
}

int sol()
{
	int ans;
	if ( !valid(D) ) return 0;
	if (D < d3) ans = (c1 + days(D) - days(d1) + 6) % 7 + 1;
	else ans = (c3 + days(D) + days(d3) + 6) % 7 + 1;
	return ans;
}

int main()
{
	int ans;
	while (D.input())
	{
		if (ans = sol()) printf("%s %d, %d is a %s\n", mon[D.m], D.d, D.y, sday[ans]);
		else printf("%d/%d/%d is an invalid date.\n", D.m, D.d, D.y);
	}
}