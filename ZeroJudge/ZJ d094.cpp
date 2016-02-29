#include <iostream>
#include <cmath>
using namespace std;

struct fig{
	char ch;
	int a;
};

struct rect{
	double xa;
	double ya;
	double xb;
	double yb;
};

struct cir{
	double x;
	double y;
	double r;
};

struct tri{
	double xa;
	double ya;
	double xb;
	double yb;
	double xc;
	double yc;
};

int main() {
	bool ox;
	char ch;
	fig a[11];
	rect b[11];
	cir c[11];
	tri d[11];
	int i,j,k,l;
	double m,n;
	i=j=k=l=1;
	while (cin>>ch&&ch!='*') {
		a[i].ch=ch;
		if (ch=='r') {
			cin>>b[j].xa>>b[j].ya>>b[j].xb>>b[j].yb;
			a[i].a=j;
			j++;
		}
		if (ch=='c') {
			cin>>c[k].x>>c[k].y>>c[k].r;
			a[i].a=k;
			k++;
		}
		if (ch=='t') {
			cin>>d[l].xa>>d[l].ya>>d[l].xb>>d[l].yb>>d[l].xc>>d[l].yc;
			a[i].a=l;
			l++;
		}
		i++;
	}
	j=1;
	while (cin>>m>>n&&(m!=9999.9||n!=9999.9)) {
		ox=1;
		for (l=1;l<i;l++) {
			if (a[l].ch=='r') {
				if (m>b[a[l].a].xa&&m<b[a[l].a].xb&&n<b[a[l].a].ya&&n>b[a[l].a].yb)
					cout<<"Point "<<j<<" is contained in figure "<<l<<endl,ox=0;
				continue;
			}
			if (a[l].ch=='c') {
				if (((m-c[a[l].a].x)*(m-c[a[l].a].x)+(n-c[a[l].a].y)*(n-c[a[l].a].y))<(c[a[l].a].r*c[a[l].a].r))
					cout<<"Point "<<j<<" is contained in figure "<<l<<endl,ox=0;
				continue;
			}
			if (a[l].ch=='t') {
				if ((m-d[a[l].a].xa)*(n-d[a[l].a].yc)!=(m-d[a[l].a].xc)*(n-d[a[l].a].ya)&&(m-d[a[l].a].xb)*(n-d[a[l].a].yc)!=(m-d[a[l].a].xc)*(n-d[a[l].a].yb)&&(m-d[a[l].a].xb)*(n-d[a[l].a].ya)!=(m-d[a[l].a].xa)*(n-d[a[l].a].yb)) {
					double zz,x1,x2,x3,y1,y2,y3;
					x1=d[a[l].a].xa-m,y1=d[a[l].a].ya-n;
					x2=d[a[l].a].xb-m,y2=d[a[l].a].yb-n;
					x3=d[a[l].a].xc-m,y3=d[a[l].a].yc-n;
					zz=0;
					zz+=acos((x1*x2+y1*y2)/sqrt(x1*x1+y1*y1)/sqrt(x2*x2+y2*y2));
					zz+=acos((x1*x3+y1*y3)/sqrt(x1*x1+y1*y1)/sqrt(x3*x3+y3*y3));
					zz+=acos((x3*x2+y3*y2)/sqrt(x3*x3+y3*y3)/sqrt(x2*x2+y2*y2));
					if (fabs(4.0*acos(0.0)-zz)<1e-6)
						cout<<"Point "<<j<<" is contained in figure "<<l<<endl,ox=0;
				}
				continue;
			}
		}
		if (ox) cout<<"Point "<<j<<" is not contained in any figure\n";
		j++;
	}
}