#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

#define MAX 110
#define DIS2(x, y) ((x) * (x) + (y) * (y))
struct point{
	double x, y;
};
bool visited[MAX];
int n, m;
int match[MAX];
int aug_path[2 * MAX], len_path;
bool r[MAX][MAX];

int find_path(int i)
{
	int j;
	for (j = 0; j < m; j++)
	{
		if (!visited[j] && r[i][j])
		{
			visited[j] = 1;
			if (match[j] < 0 || find_path(match[j]) )
			{
				match[j] = i;
				return 1;
			}
		}
	}
	return 0;
}

int maxmatch()
{
	int i, j, num = 0;
	bool ox = 1;
	for (i = 0; i < m; i++) match[i] = -1;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++) visited[j] = 0;
		if (find_path(i)) num++;
	}
	return num;
}

int main()
{
	int i, j, sum;
	double s, v, dis;
	point hog[100], hole[100];
	while (scanf("%d%d%lf%lf",&n,&m,&s,&v) != EOF)
	{
		for (i = 0; i < n; i++)
			scanf("%lf%lf", &hog[i].x, &hog[i].y);
		for (j = 0; j < m; j++)
			scanf("%lf%lf", &hole[j].x, &hole[j].y);
		dis = s * v * s * v;
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
				r[i][j] = DIS2(hole[j].x - hog[i].x, hole[j].y - hog[i].y) <= dis;
		sum = n - maxmatch();
		cout << sum << endl;
	}
}