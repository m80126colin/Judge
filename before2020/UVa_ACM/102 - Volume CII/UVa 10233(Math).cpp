#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

void FindG(int n, int &x, int &y)
{
	int m = sqrt((double) n);
	n -= m * m;
	x = n - m;
	y = 6 * (m / 2) + 2 * (m & 1) + 2 + (((n & 1) == 0) && (m & 1) != 0) - (((n & 1) != 0) && (m & 1) == 0);
	return;
}

double Dis(int x1, int y1, int x2, int y2)
{
	return sqrt(0.25 * (x1 - x2) * (x1 - x2) + 1.0 * (y1 - y2) * (y1 - y2) / 12.0);
}

int main()
{
	int n, m, x1, y1, x2, y2;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		FindG(n, x1, y1);
		FindG(m, x2, y2);
		printf("%.3lf\n", Dis(x1, y1, x2, y2));
	}
}