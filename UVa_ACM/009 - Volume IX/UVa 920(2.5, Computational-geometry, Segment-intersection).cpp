#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#define EPS 5.14e-7
#define zero(x) ((-EPS < x) && (x < EPS))
#define sign(x) ((EPS < x)?1:((x < -EPS)?-1:0))
#define myabs(x) ((sign(x) > 0)? (x): -(x))

/* point */
struct point
{
	double x, y;
	point() { x = y = 0.0; }
	point(double x, double y): x(x), y(y) {}
	bool operator < (const point& B) const { if (x != B.x) return x < B.x; return y < B.y; }
	point operator + (const point& B) { return point(x + B.x, y + B.y); }
	point& operator += (const point& b) { (*this) = (*this) + b; return (*this); }
	point operator - (const point& B) { return point(x - B.x, y - B.y); }
	point operator + (const double& b) { return point(x + b, y + b); }
	point& operator += (const double& b) { (*this) = (*this) + b; return (*this); }
	point operator * (const double& b) { return point(x * b, y * b); }
	point operator / (const double& b) { return point(x / b, y / b); }
	friend istream& operator >> (istream& in, point& B) { in >> B.x >> B.y; return in; }
	friend ostream& operator << (ostream& out, const point& B) { out << B.x << " " << B.y; return out; }
};
/* line */
struct line
{
	point a, b;
	line(){}
	line(point a, point b): a(a), b(b){}
	line(double a1, double a2, double b1, double b2): a(point(a1, a2)), b(point(b1, b2)){}
};
/* utility */
double dot(point a, point b) { return a.x * b.x + a.y * b.y; }
double cross(point a, point b) { return a.x * b.y - a.y * b.x; }
double dis(point a, point b) { return sqrt(dot(a - b, a - b)) + EPS; }
int coline(point p1, point p2, point p3) {
	return zero(cross(p2 - p1, p3 - p1));
}
int side(point p1, point p2, line L) {
	return sign(cross(L.b - L.a, p1 - L.a)) * sign(cross(L.b - L.a, p2 - L.a));
}
int line_para(line L1, line L2) {
	return zero(cross(L1.b - L1.a, L2.b - L2.a));
}
/* intersection */
int in_rect(point p, point a, point b)
{
	return min(a.x, b.x) <= p.x && p.x <= max(a.x, b.x) && min(a.y, b.y) <= p.y && p.y <= max(a.y, b.y);
}
int interl(line Seg, line L) {
	return side(Seg.a, Seg.b, L) <= 0;
}
int interseg(line L1, line L2) {
	if (!(in_rect(L1.a, L2.a, L2.b) || in_rect(L1.b, L2.a, L2.b) || in_rect(L2.a, L1.a, L1.b) || in_rect(L2.b, L1.a, L1.b))) return 0;
	return side(L1.a, L1.b, L2) <= 0 || side(L2.a, L2.b, L1) <= 0;
}
point inter_point(line L1, line L2) {
	double t = cross(L1.a - L2.a, L2.a - L2.b) / cross(L1.a - L1.b, L2.a - L2.b);
	return L1.a + (L1.b - L1.a) * t;
}
/* line */
point ptol(point p, line L) {
	double t = dot(p - L.a, L.b - L.a) / dis(L.b, L.a);
	return L.a + (L.b - L.a) * t;
}
double disptol(point p, line L) {
	return myabs(cross(p - L.a, L.b - L.a) / dis(L.b, L.a)) + EPS;
}
/* segment */
point ptoseg(point p, line L) {
	point t = p + point(L.a.y - L.b.y, L.b.x - L.a.x);
	if (side(L.a, L.b, line(p, t)) > 0) return (dis(p, L.a) < dis(p, L.b))? L.a: L.b;
	return inter_point(line(p, t), L);
}
double disptoseg(point p, line L)
{
	point t = p + point(L.a.y - L.b.y, L.b.x - L.a.x);
	if (side(L.a, L.b, line(p, t)) > 0) return min(dis(p, L.a), dis(p, L.b));
	return myabs(cross(p - L.a, L.b - L.a) / dis(L.b, L.a)) + EPS;
}
/* polygon */
#define MAXPOLY 1010
struct polygon
{
	int size;
	point poly[MAXPOLY];
	polygon(){ size = 0; }
	polygon(int n, point p[]) { for (size = 0; size < n; size++) poly[size] = p[size]; poly[size] = poly[0]; }
	int isconvex()
	{
		int i, ori = sign(cross(poly[1] - poly[0], poly[2] - poly[0]));
		for (i = 1; i < size; i++)
			if (ori * sign(cross(poly[(i + 1) % size] - poly[i], poly[(i + 2) % size] - poly[i])) < 0)
				return 0;
		return 1;
	}
	polygon convex_hull()
	{
		int i, t;
		polygon hull;
		sort(poly, poly + size);
		for (i = hull.size = 0; i < size; i++)
		{
			while (hull.size >= 2 && sign(cross(hull.poly[hull.size - 1] - hull.poly[hull.size - 2], poly[i] - hull.poly[hull.size - 2])) <= 0)
				hull.size--;
			hull.poly[hull.size++] = poly[i];
		}
		for (i = size - 2, t = hull.size + 1; i >= 0; i--)
		{
			while (hull.size >= t && sign(cross(hull.poly[hull.size - 1] - hull.poly[hull.size - 2], poly[i] - hull.poly[hull.size - 2])) <= 0)
				hull.size--;
			hull.poly[hull.size++] = poly[i];
		}
		hull.size--;
		return hull;
	}
	double perimeter()
	{
		double peri = 0.0;
		for (int i = 0; i < size; i++)
			peri += dis(poly[i], poly[i + 1]);
		return peri;
	}
	double area()
	{
		double a1 = 0.0, a2 = 0.0;
		for (int i = 0; i < size; i++)
			a1 += poly[i].x * poly[i + 1].y, a2 += poly[i].y * poly[i + 1].x;
		return myabs(a1 - a2) / 2.0;
	}
	point centroid()
	{
		point center;
		for (int i = 0; i < size; i++)
			center += (poly[i] + poly[i + 1]) * cross(poly[i], poly[i + 1]);
		return center / 6.0 / area() + EPS;
	}
	int inpolygon(point p)
	{
		int i, ori = sign(cross(poly[1] - poly[0], p - poly[0]));
		for (i = 1; i < size; i++)
			if (ori * sign(cross(poly[(i + 1) % size] - poly[i], p - poly[i])) < 0)
				return 0;
		return 1;
	}
};
/* triangle */
point tri_barycenter(point a, point b, point c) /* G */
{
	return (a + b + c) / 3.0;
}
point tri_incenter(point a, point b, point c) /* I */
{
	double x = dis(b, c), y = dis(a, c), z = dis(a, b);
	return (a * x + b * y + c * z) / (x + y + z);
}
point tri_circumcenter(point a, point b, point c) /* O */
{
	point A = c - b, B = c - a, C = b - a;
	double x = dot(A, A) * dot(B, C), y = dot(B, B) * dot(C, A), z = dot(C, C) * dot(A, B), d = 2.0 * cross(C, A) * cross(C, A);
	return (a * x + b * y + c * z) / d;
}
point tri_perpencenter(point a, point b, point c) /* H */
{
	point A = c - b, B = c - a, C = b - a;
	double x = dot(A, B) * dot(A, C), y = dot(B, A) * dot(B, C), z = dot(C, A) * dot(C, B);
	return (a * x + b * y + c * z) / (x + y + z);
}
/* circle */
struct circle
{
	double r;
	point c;
	circle(){ r = 0.0; }
	circle(point c, double r): c(c), r(r){}
};

#define MAXN 110
int c, n, sptr;
point P[MAXN];
line stack[MAXN];

double sol()
{
	int i;
	double dy, ans;
	dy = ans = 0.0;
	for (i = sptr - 1; i >= 0; i--)
	{
		ans += dis(stack[i].a, inter_point(stack[i], line(point(0.0, dy), point(1.0, dy))));
		dy = stack[i].a.y;
	}
	return ans;
}

int main()
{
	int i;
	for (scanf("%d", &c); c; c--)
	{
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			cin >> P[i];
		sort(P, P + n);
		sptr = 0;
		for (i = 0; i < n - 1; i++)
		{
			while (sptr && stack[sptr - 1].a.y < P[i].y) sptr--;
			stack[sptr++] = line(P[i], P[i + 1]);
		}
		printf("%.2lf\n", sol());
	}
}