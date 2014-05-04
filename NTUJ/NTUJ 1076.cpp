#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <iostream>
#include <algorithm>
#define EPS 1e-8
#define MAXV 110
using namespace std;

double myabs(double x) {
	return (x>0)?x:-x;
}

struct point {
	double x, y, z;
	point () {}
	point (double _x, double _y, double _z): x(_x), y(_y), z(_z) {}
	bool operator == (const point &p) {
		return x == p.x && y == p.y && z ==p.z;
	}
	bool operator == (const int &d) {
		return x == d && y == d && z == d;
	}
	bool operator != (const point &p) {
		return !((*this) == p);
	}
	bool operator != (const int &d) {
		return !((*this) == d);
	}
	point operator - (const point &p) {
		return point(x - p.x, y - p.y, z - p.z);
	}
	point operator * (const point &p) {
		return point(y * p.z - p.y * z, z * p.x - p.z * x, x * p.y - p.x * y);
	}
	double operator ^ (const point &p) {
		return x * p.x + y * p.y + z * p.z;
	}
};

struct ConvexBody{
	struct face{
		int a, b, c;
		face() {}
		face(int _a, int _b, int _c): a(_a), b(_b), c(_c) {}
	};
	int n;
	vector<face> F;
	point P[MAXV];
	int record[MAXV][MAXV];
	point normal(face &f) {
		return (P[f.b] - P[f.a]) * (P[f.c] - P[f.a]);
	}
	void convex_hull() {
		int i, j;
		for (i = 1; i < n; i++) {
			if (P[0] != P[i]) {
				swap(P[1], P[i]);
				break;
			}
		}
		if (i == n) return;
		for (i++; i < n; i++) {
			if ((P[1] - P[0]) * (P[i] - P[0]) != 0) {
				swap(P[2], P[i]);
				break;
			}
		}
		if (i == n) return;
		point tmp = (P[0] - P[1]) * (P[1] - P[2]);
		for (i++; i < n; i++) {
			if ((tmp ^ (P[0] - P[i])) != 0) {
				swap(P[3], P[i]);
				break;
			}
		}
		if (i == n) return;
		memset(record, 0, sizeof(record));
		F.clear();
		F.push_back(face(0, 1, 2));
		F.push_back(face(2, 1, 0));
		for (i = 3; i < n; i++) {
			vector<face> next;
			for (j = 0; j < F.size(); j++) {
				face &f = F[j];
				double d = (P[i] - P[f.a]) ^ normal(f);
				if (d <= 0) next.push_back(f);
				int side = 0;
				if (d > 0) side = 1;
				if (d < 0) side = -1;
				record[f.a][f.b] = record[f.b][f.c] = record[f.c][f.a] = side;
			}
			for (j = 0; j < F.size(); j++) {
				face &f = F[j];
				int a = f.a, b = f.b, c = f.c;
				if (record[a][b] > 0 && record[a][b] != record[b][a]) next.push_back(face(a, b, i));
				if (record[b][c] > 0 && record[b][c] != record[c][b]) next.push_back(face(b, c, i));
				if (record[c][a] > 0 && record[c][a] != record[a][c]) next.push_back(face(c, a, i));
			}
			F = next;
		}
	}
	double volume() {
		int i;
		double ret = 0.0;
		point o(0, 0, 0);
		for (i = 0; i < F.size(); i++) {
			face &f = F[i];
			ret += ((P[f.a] - o) * (P[f.b] - o)) ^ (P[f.c] - o);
		}
		return myabs(ret / 6.0);
	}
};

ConvexBody hull;

int main() {
	int i;
	while (scanf("%d",&hull.n), hull.n) {
		for (i = 0; i < hull.n; i++) scanf("%lf%lf%lf", &hull.P[i].x, &hull.P[i].y, &hull.P[i].z);
		hull.convex_hull();
		printf("%.2lf\n", hull.volume());
	}
}