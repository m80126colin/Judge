#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
	int i;
	const double pi=3.141592653589793;
	double x[4],y[4],d,f;
	while (cin>>x[0]>>y[0]>>x[1]>>y[1]>>x[2]>>y[2]) {
		x[3]=x[0],y[3]=y[0];
		for (d=0,f=1,i=0;i<3;i++) {
			d+=x[i]*y[i+1]-x[i+1]*y[i];
			f*=((x[i]-x[i+1])*(x[i]-x[i+1])+(y[i]-y[i+1])*(y[i]-y[i+1]));
		}
		d=fabs(d)/2;
		f=sqrt(f);
		cout<<fixed<<setprecision(2)<<(f*pi)/(d*2)<<endl;
	}
}