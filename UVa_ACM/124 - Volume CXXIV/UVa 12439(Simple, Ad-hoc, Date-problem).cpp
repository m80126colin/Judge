#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

#define MAX 2
#define MMAX 12
struct Date
{
	int y, m, d;
	string M;
	bool operator <= (const Date &D)
	{
		if (y != D.y) return y < D.y;
		if (m != D.m) return m < D.m;
		return d <= D.d;
	}
}D[MAX], s;
string month[MMAX] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
int days[MMAX] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool is_leap(int y)
{
	return (!(y % 400) || (y % 100 && !(y % 4)));
}

int sol(int y)
{
	return y / 4 - y / 100 + y / 400;
}

int main()
{
	int i, j, t, cnt, a, b;
	s.m = 2, s.d = 29;
	for (scanf("%d", &t), cnt = 1; cnt <= t; cnt++)
	{
		for (i = 0; i < MAX; i++)
		{
			cin >> D[i].M;
			scanf("%d,%d", &D[i].d, &D[i].y);
			for (j = 0; j < MMAX; j++)
				if (D[i].M == month[j])
					break;
			D[i].m = j + 1;
		}
		a = s.y = D[0].y;
		if (is_leap(D[0].y) && D[0] <= s) a = D[0].y;
		else a = D[0].y + 1;
		b = s.y = D[1].y;
		if (is_leap(D[1].y) && s <= D[1]) b = D[1].y;
		else b = D[1].y - 1;
		printf("Case %d: ", cnt);
		if (a > b) puts("0");
		else printf("%d\n", sol(b) - sol(a - 1));
	}
}