#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;

struct point{
	int x, y;
}p[8];
int n, per[8], selp[8];
double minx;

double cost(int in1, int in2) {
	return sqrt((double) (p[in1].x - p[in2].x) * (p[in1].x - p[in2].x) + (p[in1].y - p[in2].y) * (p[in1].y - p[in2].y)) + 16.0;
}

void ans() {
	int i;
	double tmp;
	do {
		for (tmp = 0, i = 1; i < n; i++) tmp += cost(per[i-1], per[i]);
		if (tmp < minx) {
			for (i = 0; i < n; i++) selp[i] = per[i];
			minx = tmp;
		}
	} while (next_permutation(per, per + n));
	return;
}

int main() {
	int i, ctr;
	for (ctr = 1; scanf("%d", &n), n; ctr++) {
		for (i = 0; i < n; i++) scanf("%d%d", &p[i].x, &p[i].y), per[i] = selp[i] = i;
		for (minx = 0, i = 1; i < n; i++) minx += cost(per[i-1], per[i]);
		ans();
		puts("**********************************************************");
		printf("Network #%d\n", ctr);
		for (i = 1; i < n; i++) printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n", p[selp[i - 1]].x, p[selp[i - 1]].y, p[selp[i]].x, p[selp[i]].y, cost(selp[i - 1], selp[i]));
		printf("Number of feet of cable required is %.2lf.\n", minx);
	}
}