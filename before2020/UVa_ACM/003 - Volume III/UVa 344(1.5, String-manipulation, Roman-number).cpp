#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

string Roman[7] = {"M", "D", "C", "L", "X", "V", "I"};
int Mod[4] = {1000, 100, 10, 1};

string NumToRoman(int n)
{
	string res = "";
	if (n == 0)
		return "ZERO";
	for (int i = 0; i < 4; i++)
	{
		int j = n / Mod[i];
		if (j == 9) res += Roman[i << 1] + Roman[(i - 1) << 1], j -= 9;
		if (j == 4) res += Roman[i << 1] + Roman[(i << 1) - 1], j -= 4;
		while (j >= 5) res += Roman[(i << 1) - 1], j -= 5;
		while (j) res += Roman[i << 1], j--;
		n %= Mod[i];
	}
	return res;
}

int Find(char ch)
{
	int i;
	for (i = 0; i < 7; i++)
		if (ch == Roman[i][0])
			return i;
	return i;
}

int RomanToNum(string roman)
{
	int pre, cur, res, sgn;
	pre = 7, res = 0;
	for (int i = roman.size() - 1; i >= 0; i--)
	{
		cur = Find(roman[i]);
		if (cur <= pre) sgn = 1, pre = cur;
		else sgn = -1;
		if (cur & 1) res += sgn * 5 * Mod[(cur + 1) >> 1];
		else res += sgn * Mod[(cur + 1) >> 1];
	}
	return res;
}

int res[101][5];
char str[10] = "ivxlc";

void sol()
{
	int i, j;
	for (j = 0; j < 5; j++)
		res[0][j] = 0;
	for (i = 1; i <= 100; i++)
	{
		for (j = 0; j < 5; j++)
			res[i][j] = res[i - 1][j];
		string s = NumToRoman(i);
		for (j = 0; j < s.size(); j++)
			res[i][6 - Find(s[j])]++;
	}
	return ;
}

int main()
{
	int num;
	sol();
	while (scanf("%d", &num), num)
	{
		printf("%d:");
		for (int i = 0; i < 5; i++)
		{
			if (i) putchar(',');
			printf(" %d %c", res[num][i], str[i]);
		}
		puts("");
	}
}