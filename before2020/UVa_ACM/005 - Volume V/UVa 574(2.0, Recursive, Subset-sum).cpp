/**
 *  @judge UVa
 *  @id 574
 *  @tag 2.0, Recursive, Subset sum
 */
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

#define MAX 51
int t, n, m, flag;
int x[MAX], tm[MAX];

void input()
{
	int i, tmp;
	memset(x, 0, sizeof(x));
	memset(tm, 0, sizeof(tm));
	for (i = m = 0; i < n; i++)
	{
		scanf("%d", &tmp);
		if (x[m] && x[m] != tmp) m++;
		if (x[m] == 0) x[m] = tmp;
		if (x[m] == tmp) tm[m]++;
	}
	m++;
	return ;
}

string MyItoA(int num)
{
	string s = "";
	while (num)
	{
		s = (char)(num % 10 + '0') + s;
		num /= 10;
	}
	if (s == "") s = "0";
	return s;
}

string tmString(int j, int num)
{
	string s, res;
	res = "";
	s = "+" + MyItoA(num);
	for (int i = 0; i < j; i++)
		res += s;
	return res;
}

void Recursive(int res, int i, string str)
{
	if (res == 0)
	{
		flag = 1;
		puts(&str[1]);
		return ;
	}
	if (i == m)
		return ;
	int j;
	for (j = tm[i]; j >= 0; j--)
		if (res - j * x[i] >= 0)
			Recursive(res - j * x[i], i + 1, str + tmString(j, x[i]));
	return ;
}

int main()
{
	while (scanf("%d%d", &t, &n), (t || n))
	{
		input();
		printf("Sums of %d:\n", t);
		flag = 0;
		Recursive(t, 0, "");
		if (!flag) puts("NONE");
	}
}