#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define N 30
#define LEN 1000010
int ans, fact[N];
char res[LEN];

void re(int n, int last, int num)
{
	int i;
	if (n == 1)
	{
		if (num > 1)
		{
			ans++;
			char tmp[1010], cur[1010];
			tmp[0] = '\0';
			for (i = 0; i < num; i++)
			{
				if (i) sprintf(cur, " %d", fact[i]); 
				else sprintf(cur, "%d", fact[i]);
				strcat(tmp, cur);
			}
			strcat(tmp, "\n");
			strcat(res, tmp);
		}
		return ;
	}
	for (i = last; i <= n; i++)
	{
		if (n % i == 0)
		{
			fact[num] = i;
			re(n / i, i, num + 1);
		}
	}
	return ;
}

void sol(int n)
{
	ans = 0;
	res[0] = '\0';
	re(n, 2, 0);
	printf("%d\n%s", ans, res);
}

int main()
{
	int n;
	while (scanf("%d", &n), n)
		sol(n);
}