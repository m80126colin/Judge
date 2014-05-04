#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

struct DD
{
	int d, m, y;
	bool operator < (const DD &D) const
	{
		if (y != D.y) return y < D.y;
		if (m != D.m) return m < D.m;
		return d < D.d;
	}
	void input()
	{
		scanf("%d/%d/%d", &d, &m, &y);
	}
}cur, birth;

void sol()
{
	int tmp;
	if (cur < birth)
	{
		puts("Invalid birth date");
		return ;
	}
	tmp = cur.y - birth.y;
	for (birth.y += tmp; cur < birth; birth.y--) tmp--;
	if (tmp > 130)
	{
		puts("Check birth date");
		return ;
	}
	printf("%d\n", tmp);
	return ;	
}

int main()
{
	int t, cnt;
	for (scanf("%d", &t), cnt = 1; cnt <= t; cnt++)
	{
		cur.input();
		birth.input();
		printf("Case #%d: ", cnt);
		sol();
	}
}