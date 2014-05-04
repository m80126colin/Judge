#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <queue>
#define MAX 1010
#define INT_MAX 2147483647
using namespace std;

int n, m;
struct edge{
	int a, b, d;
	edge() {}
	edge(int _a, int _b, int _d): a(_a), b(_b), d(_d) {}
};
vector<edge> e;


void output(FILE *fp)
{
	int i;
	fprintf(fp, "%d %d\n", n, m);
	for (i = 0; i < e.size(); i++)
	{
		fprintf(fp, "%d %d %d\n", e[i].a, e[i].b, e[i].d);
	}
	return;
}

struct vertex{
	int num, w;
	vertex() {}
	vertex(int _num, int _w): num(_num), w(_w) {}
}V[MAX];
bool visited[MAX];
int E[MAX][MAX];
long long dp[MAX];
struct comp{
	bool operator() (vertex left, vertex right)
	{
		return left.w > right.w;
	}
};

void dijkstra(int s)
{
	int i, j;
	priority_queue<vertex, vector <vertex>, comp> q;
	for (i = 1; i <= n; i++) V[i].num = i, V[i].w = INT_MAX;
	memset(visited, 0, sizeof(visited));
	V[s].w = 0;
	q.push(V[s]);
	while (!q.empty())
	{
		vertex tmp = q.top();
		q.pop();
		if (!visited[tmp.num])
		{
			V[tmp.num] = tmp;
			visited[tmp.num] = 1;
			for (j = 1; j <= n; j++)
			{
				if (!visited[j] && E[tmp.num][j]) q.push(vertex(j, tmp.w+E[tmp.num][j]));
			}
		}
	}
}
bool cmp(vertex a, vertex b)
{
	return a.w > b.w;
}
inline int DP(int a)
{
	int i, j;
	long long nMAX = 90000000;
	memset(dp, 0, sizeof(dp));
	dp[a] = 1;
	for (i = a; i <= n; i++)
	{
		for (j = a; j < i; j++)
		{
			if (E[V[i].num][V[j].num] && V[i].w < V[j].w) dp[i] += dp[j];
			if (dp[i] >= nMAX) return 0;
		}
	}
	if (dp[n] >= nMAX) return 0;
	return 1;
}
int q10917()
{
	int i;
	while (n)
	{
		memset(E, 0, sizeof(E));
		for (i = 0; i < m; i++)
		{
			E[e[i].a][e[i].b] = E[e[i].a][e[i].b] = e[i].d;
		}
		dijkstra(2);
		sort(V+1, V+n+1, cmp);
		for (i = 1; i <= n, V[i].num != 1; i++);
		return DP(i);
	}
}


/*
Q10917
1 < N <= 1000
0 <= M <= N * (N - 1) / 2
1 <= a, b <= N
1 <= d <= 1000000
*/
int line[MAX];
bool map[MAX][MAX];
int main()
{
	FILE *fp = fopen("q10917.txt", "w");
	srand(time(NULL));
	int a, b, d, i, j;
	fprintf(fp, "2 0\n2 1\n1 2 1\n8 0\n164 0\n5 3\n1 3 5\n1 4 5\n5 3 5\n4 4\n1 3 200\n1 4 100\n3 2 100\n4 2 100\n10 9\n1 3 1\n3 4 2\n4 5 3\n5 6 4\n6 7 5\n7 8 6\n8 9 7\n9 10 8\n10 2 9\n3 3\n1 2 100000\n2 3 4\n1 3 7\n4 6\n1 2 8\n2 3 985\n3 4 6542\n1 3 542\n2 4 564652\n1 4 875\n");
	/*
	for (cout << "Input n, m: "; cin >> n >> m; cout << "Input n, m: ")
	{
		if (n <= 1 || n > 1000 || m < 0 || m > n * (n - 1) / 2)
		{
			cout << "測資不合!!" << endl;
			continue;
		}
		fprintf(fp, "%d %d\n", n, m);
		for (i = 0; i < m; i++)
		{
			cout << "i = " << i << " , cin a, b, d: ";
			//cin >> a >> b >> d;
			if (a <= 0 || a > n || b <= 0 || b > n || d <= 0 || d > 1000000)
			{
				cout << "測資不合!!" << endl;
				i--;
				continue;
			}
			fprintf(fp, "%d %d %d\n", a, b, d);
		}
	}
	*/
	for (i = 0; i < 10; i++)
	{
		e.clear();
		int st = rand() % 8;
		if (st)
		{
			if (st == 1)
			{
				n = (rand() % 100) + 2;
				m = n * (n - 1) / 2;
				for (a = 1; a <= n; a++)
				{
					for (b = a + 1; b <= n; b++)
					{
						d = (rand() % 1000000) + 1;
						e.push_back(edge(a, b, d));
					}
				}
				if (q10917()) output(fp);
				else i--;
			}
			else
			{
				n = (rand() % 100) + 2;
				m = n - 1;
				for (a = 1; a < n; a++)
				{
					d = (rand() % 1000000) + 1;
					e.push_back(edge(a, a+1, d));
				}
				if (q10917()) output(fp);
				else i--;
			}
		}
		else {
			n = (rand() % 998) + 2;
			m = 0;
			if (q10917()) output(fp);
			else i--;
		}
	}
	for (i = 0; i < 6000; i++)
	{
		e.clear();
		memset(map, 0, sizeof(map));
		memset(line, 0, sizeof(line));
		n = (rand() % 30) + 2;
		m = (rand() * rand()) % (n * (n - 1) / 2) + 1;
		for (j = 0; j < m; j++)
		{
			a = (rand() % n) + 1;
			b = (rand() % n) + 1;
			while (line[a] >= n || line[b] >= n || a == b || map[a][b]) a = (rand() % n) + 1, b = (rand() % n) + 1;
			d = (rand() % 1000000) + 1;
			e.push_back(edge(a, b, d));
			map[a][b] = map[b][a] = 1;
			line[a]++, line[b]++;
		}
		if (q10917()) output(fp);
		else i--;
	}
	fprintf(fp, "0\n");
}