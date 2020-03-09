/**
 *  @judge ZeroJudge
 *  @id d047
 *  @source UVa 10070
 * 
 *  @tag Simple, Math
 */
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

string y;

inline int ctoi(char ch)
{
	return ch - '0';
}

bool div_3()
{
	int i, ans = 0;
	for (i = 0; i < y.size(); i++)
		ans += ctoi(y[i]);
	return (ans % 3 == 0);
}

bool div_5()
{
	int i = y.size() - 1;
	return y[i] == '0' || y[i] == '5';
}

bool div_11()
{
	int i, odd, even;
	odd = even = 0;
	for (i = 0; i < y.size(); i++)
	{
		if (i & 1) odd += ctoi(y[i]);
		else even += ctoi(y[i]);
	}
	return (odd - even) % 11 == 0;
}

bool div_4()
{
	int i;
	i = y.size() - 1;
	if (y.size() < 2)
		return y[i] == '0' || y[i] == '4' || y[i] == '8';
	int num = 0;
	for (i = y.size() - 2; i < y.size(); i++)
	{
		num *= 10;
		num += ctoi(y[i]);
	}
	return (num % 4 == 0);
}

bool div_100()
{
	if (y.size() < 3)
		return 0;
	int i = y.size() - 2;
	return y[i] == '0' && y[i + 1] == '0';
}

bool div_400()
{
	if (y.size() < 3)
		return 0;
	int i = y.size() - 3;
	if (y.size() < 4)
		return y[i] == '0' || y[i] == '4' || y[i] == '8';
	int num = 0;
	i = y.size() - 4;
	num = ctoi(y[i]) * 10 + ctoi(y[i + 1]);
	i = y.size() - 2;
	return (num % 4 == 0) && y[i] == '0' && y[i + 1] == '0';
}

bool isleap()
{
	return div_400() || (div_4() && (!div_100()));
}

bool ishulu()
{
	return div_3() && div_5();
}

bool isbulu()
{
	return div_5() && div_11();
}

int main()
{
	bool a, b, c;
	int flag;
	for (flag = 0; cin >> y; flag++)
	{
		if (flag) puts("");
		a = isleap();
		b = ishulu();
		c = a && isbulu();
		if (a || b || c)
		{
			if (a) puts("This is leap year.");
			if (b) puts("This is huluculu festival year.");
			if (c) puts("This is bulukulu festival year.");
		}
		else puts("This is an ordinary year.");
	}
}