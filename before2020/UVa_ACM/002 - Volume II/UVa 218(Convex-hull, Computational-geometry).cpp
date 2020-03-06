/**
 *  @judge UVa
 *  @id 218
 *  @tag Convex hull, Computational geometry
 */
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

#define EPS 5.14e-7
template <class T>
class Point
{
public:
	T x, y;
	Point() {}
	Point(T x, T y): x(x), y(y) {}
	bool operator < (const Point& B) const { if (x > B.x + EPS || x < B.x - EPS) return x < B.x; return y < B.y; }
	double operator * (const Point& B) const { return (double) x * B.x + y * B.y; } // dot
	double operator ^ (const Point& B) const { return (double) x * B.y - y * B.x; } // cross
	Point operator + (const Point& B) { return Point(x + B.x, y + B.y); }
	Point operator + (const double& b) {return Point(x + b  , y + b  ); }
	Point& operator += (const Point& B) { (*this) = Point(x + B.x, y + B.y); return (*this); }
	Point operator - (const Point& B) { return Point(x - B.x, y - B.y); }
	Point operator * (const double& b) {return Point(x * b  , y * b  ); }
	Point operator / (const double& b) {return Point(x / b  , y / b  ); }
	operator Point<double>() const { return Point<double>((double) x, (double) y); } // cast
	friend istream& operator >> (istream& in, Point& B) { in >> B.x >> B.y; return in; }
	friend ostream& operator << (ostream& out, const Point& B) { out << B.x << " " << B.y; return out; }
};


#define MAX 100010
template <class T>
class Polygon
{
public:
	int PointSize, HullSize;
	Point<T> P[MAX], Hull[2 * MAX];
	Polygon() { PointSize = HullSize = 0; }
	void Sort() { sort(P, P + PointSize); }
	void Clear() { PointSize = HullSize = 0; }
	void ConvexHull() { // include the initial point twice
		int i, t;		// convex hull in clockwise
		for (i = HullSize = 0; i < PointSize; i++)
		{
			while (HullSize >= 2 && ((Hull[HullSize - 1] - Hull[HullSize - 2]) ^ (P[i] - Hull[HullSize - 2])) <= 0) HullSize--;
			Hull[ HullSize++ ] = P[i];
		}
		for (t = HullSize + 1, i = PointSize - 2; i >= 0; i--)
		{
			while (HullSize >= t && ((Hull[HullSize - 1] - Hull[HullSize - 2]) ^ (P[i] - Hull[HullSize - 2])) <= 0) HullSize--;
			Hull[ HullSize++ ] = P[i];
		}
		HullSize--;
		return;
	}
	double Perimeter()
	{
		double peri = 0.0;
		for (int i = 0; i < HullSize; i++)
			peri += sqrt( (Hull[i + 1] - Hull[i]) * (Hull[i + 1] - Hull[i]) );
		return peri;
	}
	double Area() {
		double area = 0.0;
		for (int i = 0; i < HullSize; i++)
			area += (Hull[i] ^ Hull[i + 1]);
		if (area < 0) area = -area;
		return area / 2.0;
	}
	Point<double> MassCenter() { // calculate the center of mass
		Point<double> Center(0.0, 0.0);
		for (int i = 0; i < HullSize; i++)
			Center += (Point<double>) (Hull[i] + Hull[i + 1]) * (Hull[i] ^ Hull[i + 1]);
		return Center / 6.0 / Area() + EPS;
	}
	bool InPoly(Point<T> B) // whether the point in the polygon or not
	{
		int i;
		double test, tmp = ((Hull[1] - Hull[0]) ^ (B - Hull[0]));
		for (i = 1; i < HullSize; i++)
		{
			test = ((Hull[i + 1] - Hull[i]) ^ (B - Hull[i]));
			if (!((test > 0 && tmp > 0) || (test < 0 && tmp < 0))) return 0;
		}
		return 1;
	}
	friend istream& operator >> (istream& in, Polygon& Poly) { cin >> Poly.P[ Poly.PointSize++ ]; return in; }
};
Polygon<double> CH;

int main()
{
	int n, t, i;
	for (t = 1; scanf("%d", &n), n; t++)
	{
		if (t > 1) puts("");
		CH.Clear();
		for (i = 0; i < n; i++)
			cin >> CH;
		CH.Sort();
		CH.ConvexHull();
		printf("Region #%d:\n", t);
		for (i = CH.HullSize; i >= 0; i--)
		{
			printf("(%.1lf,%.1lf)", CH.Hull[i].x, CH.Hull[i].y);
			if (i) putchar('-');
		}
		puts("");
		printf("Perimeter length = %.2lf\n", CH.Perimeter());
	}
}