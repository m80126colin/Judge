#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

double a[201][201];

int main() {
	int i,j,k,n,t,x[201],y[201];
	for (t=1;cin>>n,n;t++) {
		for (i=1;i<=n;i++) {
			cin>>x[i]>>y[i];
			for (j=i-1;j;j--) a[j][i]=a[i][j]=sqrt((double) (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
		}
		for (k=1;k<=n;k++) {
			for (i=1;i<=n;i++) {
				for (j=1;j<=n;j++) {
					a[i][j]=min(a[i][j],max(a[i][k],a[k][j]));
				}
			}
		}
		if (t>1) cout<<endl;
		cout<<"Scenario #"<<t<<endl<<"Frog Distance = "<<fixed<<setprecision(3)<<a[1][2]<<endl;
	}
}