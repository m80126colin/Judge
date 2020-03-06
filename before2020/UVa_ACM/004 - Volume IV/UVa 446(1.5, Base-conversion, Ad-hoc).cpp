/**
 *  @judge UVa
 *  @id 446
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
	string res = "";
	for (int i = 0; i < 13; i++)
	{
		char ch = getValue[num % base];
		res = ch + res;
		num /= base;
	}
	return res;
}

int main()
{
	char op[5];
	int a, b, n;
	for (scanf("%d", &n); n; n--)
	{
		scanf("%x%s%x", &a, op, &b);
		printf("%s %s %s = ",MyItoA(a, 2).c_str(), op, MyItoA(b, 2).c_str());
		if (op[0] == '+') printf("%d\n", a + b);
		else printf("%d\n", a - b);
	}
}