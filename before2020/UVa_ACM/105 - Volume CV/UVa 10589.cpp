#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
	int n,a,m,g;
	double n1,n2,a1,a2,a3,a4;
	cout<<showpoint<<fixed;
	for (cin>>n>>a;n&&a;cin>>n>>a) {
		g=n;
		for (m=0;g;g--) {
			cin>>n1>>n2;
			a1=sqrt(n1*n1+n2*n2);
			a2=sqrt((n1-a)*(n1-a)+n2*n2);
			a3=sqrt((n1-a)*(n1-a)+(n2-a)*(n2-a));
			a4=sqrt(n1*n1+(n2-a)*(n2-a));
			if ((a1<=a)&&(a2<=a)&&(a3<=a)&&(a4<=a)) m++;
		}
		n1=((double)((double) m/n)*a*a);
		cout<<setprecision(5)<<n1<<endl;
	}
}