#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <iostream>
#include <deque>
#include <queue>
#define MAX 256
using namespace std;

int n;
int visited[MAX], map[MAX][MAX];
deque<int> hamilton;

int input() {
	char ch;
	int d;
	while (!isdigit(ch = getchar())) if (ch == '%') return 0;
	for (d = 0; isdigit(ch); ch = getchar())
		d = d * 10 + ch - '0';
	return d;
}

int find_path()
{
	int i;
	for (i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			if (map[hamilton[hamilton.size()-1]][i])
			{
				hamilton.push_back(i);
				visited[i] = 1;
				return 1;
			}
			else if (map[hamilton[0]][i])
			{
				hamilton.push_front(i);
				visited[i] = 1;
				return 1;
			}
		}
	}
	return 0;
}

int extend()
{
	int i, j;
	for (j = 1; j <= n; j++) if (!visited[j]) break;
	for (i = 0; i < hamilton.size(); i++) {
		if (map[hamilton[i]][j]) {
			if (i < hamilton.size() - 1) {
				queue <int> s;
				while (!s.empty()) s.pop();
				while (i + 1 < hamilton.size()) s.push(hamilton[hamilton.size()-1]), hamilton.pop_back();
				while (!s.empty()) hamilton.push_front(s.front()), s.pop();
			}
			else hamilton.push_back(j);
			return 1;
		}
	}
	return 0;
}

int find_ring() {
	int i, j;
	for (i = 0; i < hamilton.size() - 1; i++) {
		if (map[hamilton[i]][hamilton[hamilton.size()-1]] && map[hamilton[i+1]][hamilton[0]]) {
			for (j = 1; j <= (hamilton.size()-i-1)/2; j++)
				swap(hamilton[i+j], hamilton[hamilton.size()-j]);
			return 1;
		}
	}
	return 0;
}

int circuit() {
	hamilton.push_back(1);
	visited[1] = 1;
	while (hamilton.size() < n) {
		while (find_path());
		if (!map[hamilton.front()][hamilton.back()])
			if (!find_ring()) return 0;
		if (hamilton.size() == n) return 1;
		if (!extend()) return 0;
	}
	return 1;
}

int main()
{
	int i, j;
	while (scanf("%d", &n) != EOF)
	{
		memset(visited, 0, sizeof(visited));
		memset(map, 0, sizeof(map));
		hamilton.clear();
		while (i = input()) {
			j = input();
			if (i != j) {
				map[i][j]++;
				map[j][i]++;
			}
		}
		if (circuit()) {
			for (i = 0; i < hamilton.size(); i++) printf("%d ", hamilton[i]);
			printf("%d\n", hamilton[0]);
		}
		else puts("N");
	}
}