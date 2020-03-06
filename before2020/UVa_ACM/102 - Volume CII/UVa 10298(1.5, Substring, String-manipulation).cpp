/**
 *  @judge UVa
 *  @id 10298
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
	int n = str.size(), res = 1, sq = sqrt((double) n);
	for (int i = 1; i <= sq; i++)
	{
		if (n % i == 0)
		{
			if (isPeriod(i))
				res = max(res, n / i);
			if (isPeriod(n / i))
				res = max(res, i);
		}
	}
	return res;
}

int main()
{
	while (cin >> str, str != ".")
		printf("%d\n", sol());
}