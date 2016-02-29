#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int t, i, j;
long long a, b;
long long com[39] = {1,4,9,121,484,10201,12321,14641,40804,44944,1002001,1234321,4008004,100020001,102030201,104060401,121242121,123454321,125686521,400080004,404090404,10000200001,10221412201,12102420121,12345654321,40000800004,1000002000001,1002003002001,1004006004001,1020304030201,1022325232201,1024348434201,1210024200121,1212225222121,1214428244121,1232346432321,1234567654321,4000008000004,4004009004004};

int main()
{
	// freopen("C-large-1.in", "r+", stdin);
	// freopen("C-large-1.out", "w+", stdout);
	int cnt;
	for (scanf("%d", &t), cnt = 1; cnt <= t; cnt++)
	{
		scanf("%lld%lld", &a, &b);
		i = lower_bound(com, com + 39, a) - com;
		j = upper_bound(com, com + 39, b) - com;
		printf("Case #%d: %d\n", cnt, j - i);
	}
}