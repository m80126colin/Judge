#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <map>
using namespace std;

inline
int getdigit(int x)
{
	int ans;
	for (ans = 0; x; x /= 10)
		ans++;
	return ans;
}

inline
int arrange(int x)
{
	int i, div, mul;
	int digit, re[10];
	digit = getdigit(x);
	for (i = 0, mul = 1; i < digit; i++)
		mul *= 10;
	for (i = 0, div = 1; i < digit; i++)
	{
		re[i] = x % div * mul + x / div;
		div *= 10;
		mul /= 10;
	}
	sort(re, re + digit);
	for (i = 0; i < digit; i++)
		if (getdigit(re[i]) == digit)
			break ;
	return re[i];
}

int main()
{
	//freopen("C-large.in","r+",stdin);
	//freopen("C-large.out","w+",stdout);
	int ans;
	int t, ctr, A, B, i;
	//map<int, int> M;
	static int M[2000010];
	//map<int,int>::iterator it;
	for (scanf("%d", &t), ctr = 1; ctr <= t; ctr++)
	{
		ans = 0;
		memset(M, 0, sizeof(M));
		scanf("%d%d", &A, &B);
		for (i = A; i <= B; i++)
			M[arrange(i)]++;
		for (i = A; i <= B; i++)
			if (M[i] > 1)
				ans += M[i] * (M[i] - 1) / 2;
		printf("Case #%d: %d\n", ctr, ans);
	}
}