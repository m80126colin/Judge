/**
 *  @judge ZeroJudge
 *  @id d251
 *  @tag 1.5, String Manipulation, Roman number
 */
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

int main()
{
	string a, b;
	int mm;
	while (cin >> a >> b)
	{
		mm = 60 * RomanToNum(a) + RomanToNum(b) + 60 * 7 + 30;
		if (mm >= 24 * 60) mm -= 24 * 60;
		printf("%s\n%s\n", NumToRoman(mm / 60).c_str(), NumToRoman(mm % 60).c_str());
	}
}