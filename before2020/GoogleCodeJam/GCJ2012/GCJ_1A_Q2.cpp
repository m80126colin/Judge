#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
struct LV
{
	int a, b, isa;
	LV(){a=b=isa=0;}
	LV(int a, int b): a(a), b(b){isa=0;}
};
vector<LV> L;
int star;

int cmp1(LV left, LV right)
{
	return left.b < right.b;
}

int cmp2(LV left, LV right)
{
	if (left.a != right.a)
		return left.a < right.a;
	return left.b > right.b;
}

int sol()
{
	int i;
	int ans = 0;
	star = 0;
	sort(L.begin(), L.end(), cmp1);
	while (!L.empty())
	{
		while (!L.empty() && star >= L[0].b)
		{
			if (L[0].isa) star++;
			else star += 2;
			L.erase(L.begin());
			ans++;
		}
		if (L.empty())
			return ans;
		//sort(L.begin(), L.end(), cmp2);
		for (i = L.size() - 1; i >= 0; i--)
		{
			if ((!L.empty()) && star >= L[i].a && (!L[i].isa))
			{
				star++;
				L[i].isa = 1;
				ans++;
				break;
			}
		}
		if (i < 0)
			return 0;
	}
	return ans;
}

int main()
{
	int t, ctr;
	int i, tmp1, tmp2;
	freopen("B-small-attempt1.in","r",stdin);
	freopen("1A_Q2_test.out","w+",stdout);
	scanf("%d", &t);
	for (ctr = 1; ctr <= t; ctr++)
	{
		scanf("%d", &n);
		L.clear();
		for (i = 0; i < n; i++)
		{
			scanf("%d%d", &tmp1, &tmp2);
			L.push_back(LV(tmp1, tmp2));
		}
		printf("Case #%d: ", ctr);
		if ((i = sol()) > 0)
			printf("%d\n", i);
		else puts("Too Bad");
	}
}