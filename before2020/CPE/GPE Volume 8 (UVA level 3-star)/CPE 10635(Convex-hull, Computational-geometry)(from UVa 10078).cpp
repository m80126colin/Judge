/**
 *  @judge CPE
 *  @id 10635
 *  @tag Convex hull, Computational geometry
 */
#include <iostream>
using namespace std;

struct point{
	int x;
	int y;
}a[50];

int cross (point x,point y,point z) {
	return (y.x-x.x)*(z.y-x.y)-(z.x-x.x)*(y.y-x.y);
}

bool D(int x) {
	for (int i=1;i<x;i++) {
		if (cross(a[i-1],a[i%x],a[(i+1)%x])*cross(a[i],a[(i+1)%x],a[(i+2)%x])<0) return 1;
	}
	return 0;
}

int main() {
	int i,j;
	while (cin>>i,i) {
		for (j=0;j<i;j++) cin>>a[j].x>>a[j].y;
		cout<< ((D(j)) ? "Yes" : "No" ) <<endl;
	}
}