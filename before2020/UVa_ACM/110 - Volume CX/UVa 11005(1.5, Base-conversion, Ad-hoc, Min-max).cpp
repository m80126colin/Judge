/**
 *  @judge UVa
 *  @id 11005
 *  @tag 1.5, Number Base Conversion, Ad-hoc, Min max
 */
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

string getValue = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int value[50], ans[50];

string MyItoA(int num, int base)
{
	if (num == 0)
		return "0";
	string res = "";
	while (num)
	{
		char ch = getValue[num % base];
		ans[base] += value[num % base];
		res = ch + res;
		num /= base;
	}
	return res;
}

int MyAtoI(string num, int base)
{
	int res = 0;
	for (int i = 0; i < num.size(); i++)
	{
		res *= base;
		if (num[i] >= '0' && num[i] <= '9') res += num[i] - '0';
		else res += num[i] - 'A' + 10;
	}
	return res;
}

void sol()
{
	int i, n, len, mn = 2147483647;
	scanf("%d", &n);
	for (i = 2; i <= 36; i++)
	{
		ans[i] = 0;
		MyItoA(n, i);
		mn = min(mn, ans[i]);
	}
	printf("Cheapest base(s) for number %d:", n);
	for (i = 2; i <= 36; i++)
		if (ans[i] == mn) printf(" %d", i);
	puts("");
}

int main()
{
	int t, cnt, i, m;
	for (scanf("%d", &t), cnt = 1; cnt <= t; cnt++)
	{
		if (cnt > 1) puts("");
		for (i = 0; i < 36; i++)
			scanf("%d", &value[i]);
		printf("Case %d:\n", cnt);
		for (scanf("%d", &m); m; m--)
			sol();
	}
}