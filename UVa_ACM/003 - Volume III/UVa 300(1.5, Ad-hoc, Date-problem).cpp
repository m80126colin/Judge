#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

string Haab[20] = {
	"pop", "no", "zip", "zotz", "tzec",
	"xul", "yoxkin", "mol", "chen", "yax",
	"zac", "ceh", "mac", "kankin", "muan", 
	"pax", "koyab", "cumhu", "uayet"
};
string Tzolkin[20] = {
	"imix", "ik", "akbal", "kan", "chicchan",
	"cimi", "manik", "lamat", "muluk", "ok",
	"chuen", "eb", "ben", "ix", "mem",
	"cib", "caban", "eznab", "canac", "ahau"
};

struct Date {
	char mm[20];
	int d, m, y;
}date, new_date;

void input()
{
	scanf("%d.%s%d", &date.d, date.mm, &date.y);
	for (int i = 0; i < 20; i++)
		if (Haab[i] == date.mm)
		{
			date.m = i;
			return ;
		}
	return ;
}

void sol()
{
	int tot = date.y * 365 + date.m * 20 + date.d;
	new_date.y = tot / 260;
	tot %= 260;
	new_date.m = tot % 20;
	new_date.d = tot % 13;
	printf("%d %s %d\n", new_date.d + 1, Tzolkin[new_date.m].c_str(), new_date.y);
}

int main()
{
	int t;
	scanf("%d", &t);
	printf("%d\n", t);
	while (t)
	{
		input();
		sol();
		t--;
	}
}