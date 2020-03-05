#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <functional>
using namespace std;

int n;
struct Student
{
	int a[5];
	bool operator < (Student right) const
	{
		int i;
		for (i = 0; i < 5; i++)
			if (a[i] != right.a[i])
				return a[i] < right.a[i];
		return false;
	}
	bool operator == (Student right) const
	{
		int i;
		for (i = 0; i < 5; i++)
			if (a[i] != right.a[i])
				return false;
		return true;
	}
}stu[10010];
int re[10010];

int main()
{
	int i, j, ans;
	while (scanf("%d", &n), n)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < 5; j++)
				scanf("%d", &stu[i].a[j]);
			sort(stu[i].a, stu[i].a + 5);
		}
		sort(stu, stu + n);
		re[0] = 1;
		for (i = 1; i < n; i++)
		{
			if (stu[i - 1] == stu[i]) re[i] = re[i - 1] + 1;
			else re[i] = 1;
		}
		sort(re, re + n, greater<int>());
		ans = 0;
		for (i = 0; i < n; i++)
		{
			if (re[i] == re[0])
				ans += re[i];
			else break;
		}
		printf("%d\n", ans);
	}
}