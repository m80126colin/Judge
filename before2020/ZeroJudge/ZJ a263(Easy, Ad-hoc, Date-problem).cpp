#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#define MAX 2
struct Date
{
	int y, m, d;
}date[MAX];
int tot[MAX];

int input()
{
	int i;
	for (i = 0; i < MAX; i++)
		if (scanf("%d%d%d", &date[i].y, &date[i].m, &date[i].d) == EOF)
			return 0;
	return 1;
}

int is_leap(int y)
{
	if (!(y % 400) || (y % 100 && !(y % 4)))
		return 1;
	return 0;
}

int month[13] = {0, 31, 28, 31, 30, 31, 30,
					31, 31, 30, 31, 30, 31};

int count(Date D)
{
	int i, ans, tmp;
	tmp = D.y - 1;
	ans = tmp * 365 + tmp / 4 - tmp / 100 + tmp / 400;
	for (i = 1; i < D.m; i++)
	{
		ans += month[i];
		if (i == 2 && is_leap(D.y)) ans++;
	}
	ans += D.d;
	return ans;
}

void convert()
{
	int i;
	for (i = 0; i < MAX; i++)
		tot[i] = count(date[i]);
	return ;
}

int main()
{
	while (input())
	{
		convert();
		printf("%d\n", abs(tot[0] - tot[1]));
	}
}