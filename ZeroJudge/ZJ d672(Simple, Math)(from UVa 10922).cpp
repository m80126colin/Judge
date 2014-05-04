#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int deg, ans;
string num;

int div_9()
{
	deg = 0;
	while (ans >= 10)
	{
		if (ans % 9 == 0) deg++;
		else return deg;
		int tmp = ans;
		ans = 0;
		while (tmp)
		{
			ans += tmp % 10;
			tmp /= 10;
		}
	}
	if (ans % 9 == 0) deg++;
	return deg;
}

int main()
{
	int i;
	while (cin >> num, num != "0")
	{
		ans = 0;
		for (i = 0; i < num.size(); i++)
			ans += num[i] - '0';
		if (div_9()) printf("%s is a multiple of 9 and has 9-degree %d.\n", num.c_str(), deg);
		else printf("%s is not a multiple of 9.\n", num.c_str());
	}
}