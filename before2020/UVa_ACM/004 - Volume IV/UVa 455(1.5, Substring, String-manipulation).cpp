/**
 *  @judge UVa
 *  @id 455
 *  @tag 1.5, Substring, String manipulation
 */
#include <cstdio>
#include <string>
#include <cmath>
#include <iostream>
using namespace std;

string str;

int isPeriod(int len) {
	string s = str.substr(0, len);
	for (int i = len; i < str.size(); i += len)
		if (s != str.substr(i, len))
			return 0;
	return 1;
}

int sol()
{
	int n = str.size(), res = str.size(), sq = sqrt((double) n);
	for (int i = 1; i <= sq; i++)
	{
		if (n % i == 0)
		{
			if (isPeriod(i))
				res = min(res, i);
			if (isPeriod(n / i))
				res = min(res, n / i);
		}
	}
	return res;
}

int main()
{
	int n;
	for (scanf("%d", &n); n; n--)
	{
		cin >> str;
		printf("%d\n", sol());
		if (n > 1) puts("");
	}
}