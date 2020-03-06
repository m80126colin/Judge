/**
 *  @judge UVa
 *  @id 389
 *  @tag 1.5, Base conversion, Ad hoc
 */
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

string getValue = "0123456789ABCDEF";

string MyItoA(int num, int base)
{
	if (num == 0)
		return "0";
	string res = "";
	while (num)
	{
		char ch = getValue[num % base];
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

int main()
{
	char str[20];
	string res;
	int a, b;
	while (scanf("%s%d%d", str, &a, &b) != EOF)
	{
		res = MyItoA(MyAtoI(str, a), b);
		if (res.size() > 7) puts("  ERROR");
		else printf("%7s\n", res.c_str());
	}
}