#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int x[5],y[5],i,n;
	double a[2],b[2],c[2];
	cout<<"INTERSECTING LINES OUTPUT\n";
	for(cin>>n;n;n--) {
		for (i=1;i<=4;i++) cin>>x[i]>>y[i];
		if ((x[1]-x[2])*(y[3]-y[4])==(y[1]-y[2])*(x[3]-x[4])) {
			if ((x[2]-x[3])*(y[1]-y[4])==(y[2]-y[3])*(x[1]-x[4])) cout<<"LINE\n";
			else cout<<"NONE\n";
		}
		else {
			for (i=1;i<=2;i++) {
				a[i-1]=y[2*i-1]-y[2*i];
				b[i-1]=x[2*i-1]-x[2*i];
				c[i-1]=a[i-1]*x[2*i-1]-b[i-1]*y[2*i-1];	
			}
			cout<<fixed<<setprecision(2)<<"POINT "<<(c[0]*b[1]-c[1]*b[0])/(a[0]*b[1]-a[1]*b[0])<<" "<<(c[0]*a[1]-c[1]*a[0])/(a[0]*b[1]-a[1]*b[0])<<endl;
		}
	}
	cout<<"END OF OUTPUT\n";
}