#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
using namespace std;

int col[10] = {0, 1, 2, 3, 1, 2, 3, 1, 2, 3};
string s;

int reach(string t, char cur, int ox)
{
	if (ox) return col[cur - '0'] >= col[t[0] - '0'];
	return col[cur - '0'] <= col[t[1] - '0'];
}

int step(string t, int ox)
{
	int i, cnt;
	cnt = col[t[1] - '0'] < col[t[0] - '0'];
	for (i = 2; i < s.size(); i++)
	{
		if (reach(t, s[i], ox))
		{
			t[ox] = s[i];
			ox++;
			ox &= 1;
		}
		else
		{
			t[ox^1] = s[i];
			cnt++;
		}
	}
	return cnt;
}

int main()
{
	string a, b;
	while (getline(cin, s), s != "#")
	{
		if (s.size() <= 2) puts("0");
		else
		{
			a = b = s.substr(0, 2);
			swap(b[0], b[1]);
			printf("%d\n", min(step(a, 0), step(b, 1)) );
		}
	}
}