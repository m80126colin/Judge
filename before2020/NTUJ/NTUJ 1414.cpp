#include <stdio.h>
#include <iostream>
#include <algorithm>
#define MAX 110
using namespace std;

struct point{
	int x, y;
}p[MAX], entry, selp[MAX];

int n, mid;

int cross(point o, point a, point b) {
	return (a.x - o.x) * (b.y - o.y) - (b.x - o.x) * (a.y - o.y);
}

bool cmp(point a, point b) {
	return a.x < b.x || (a.x == b.x && a.y < b.y);
}

int ConVexHull() {
	int i, j = 0, t;
	sort(p, p+n, cmp);
	for (i = 0; i < n; i++) {
		while(j >= 2 && cross(selp[j - 2], selp[j - 1], p[i]) <= 0) j--;
		selp[j++] = p[i];
	}
	for (i = n - 1, t = j + 1; i >= 0; i--) {
		while (j >= t && cross(selp[j - 2], selp[j - 1], p[i]) <= 0) j--;
		selp[j++] = p[i];
	}
	return j;
}

int area(int j) {
	int i, ans = 0;
	selp[j] = selp[0];
	for (i = 0; i < j; i++)
		ans += selp[i].x * selp[i + 1].y - selp[i + 1].x * selp[i].y;
	return abs(ans);
}

int main() {
	int t, i, size, ans;
	entry.x = entry.y = 0;
	for (scanf("%d", &t); t; t--) {
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			scanf("%d%d", &p[i].x, &p[i].y);
		size = ConVexHull();
		ans = area(size);
		if (ans & 1)
			printf("%d.500000\n", ans / 2);
		else
			printf("%d.000000\n", ans / 2);
	}
}