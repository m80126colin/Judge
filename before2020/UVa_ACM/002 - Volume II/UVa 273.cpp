#include <iostream>
#include <vector>
using namespace std;

struct point{
	int x,y;
};

struct line{
	point p1,p2;
}p[13];

int map[13];

inline int cross(point r,point x,point y) {
	return (x.x-r.x)*(y.y-r.y)-(x.y-r.y)*(y.x-r.x);
}

inline bool connected(line x,line y) {
	if (max(x.p1.x,x.p2.x)>=min(y.p1.x,y.p2.x)&&max(y.p1.x,y.p2.x)>=min(x.p1.x,x.p2.x)&&max(x.p1.y,x.p2.y)>=min(y.p1.y,y.p2.y)&&max(y.p1.y,y.p2.y)>=min(x.p1.y,x.p2.y)) {
		if (cross(x.p1,x.p2,y.p1)*cross(x.p1,x.p2,y.p2)<=0&&cross(y.p1,y.p2,x.p1)*cross(y.p1,y.p2,x.p2)<=0) return 1;
		else return 0;
	}
	else return 0;
}

inline int find(int x) {
	while (map[x]!=x) x=map[x];
	return x;
}

int main() {
	int t,n,i,j;
	for (cin>>t;t;t--) {
		for (i=1;i<13;i++) map[i]=i;
		for (cin>>n,i=1;i<=n;i++) scanf("%d %d %d %d",&p[i].p1.x,&p[i].p1.y,&p[i].p2.x,&p[i].p2.y);
		for (i=1;i<=n;i++) {
			for (j=i+1;j<=n;j++) {
				if (connected(p[i],p[j])) map[find(i)]=map[find(j)];
			}
		}
		while (cin>>i>>j,i||j) printf( (map[find(i)]==map[find(j)]) ? "CONNECTED\n" : "NOT CONNECTED\n");
		if (t>1) cout<<endl;
	}
}