#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

string MyItoA(int n)
{
	string res = "";
	if (n == 0)
		return "0";
	while (n)
	{
		char ch = '0' + n % 3;
		res = ch + res;
		n /= 3;
	}
	return res;
}

int main()
{
	int n;
	while (scanf("%d", &n), n >= 0)
		puts(MyItoA(n).c_str());
}