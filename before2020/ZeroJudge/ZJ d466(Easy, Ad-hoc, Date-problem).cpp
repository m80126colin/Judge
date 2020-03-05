#include <stdio.h>
#include <iostream>
using namespace std;

int yy, mm, dd;
int mon[13]= {0, 31, 28, 31, 30, 31, 30
			   , 31, 31, 30, 31, 30, 31};

int is_leap()
{
	if (!(yy % 400) || (yy % 100 && !(yy % 4)))
		return 1;
	return 0;
}

int valid()
{
	if (yy < 1 || mm < 1 || mm > 12)
		return 0;
	if (dd < 1 || dd > mon[mm] + (mm == 2 && is_leap()))
		return 0;
	return 1;
}

int main()
{
	int i, ans;
	while (scanf("%d%d%d", &yy, &mm, &dd) != EOF)
	{
		if (valid())
		{
			ans = 0;
			for (i = 1; i < mm; i++)
			{
				ans += mon[i];
				if (i == 2 && is_leap()) ans++;
			}
			ans += dd;
			printf("It is ");
			if (ans == 1) printf("1 day");
			else printf("%d days", ans);
			printf(" in %d\n", yy);
		}
		else puts("Error");
	}
}