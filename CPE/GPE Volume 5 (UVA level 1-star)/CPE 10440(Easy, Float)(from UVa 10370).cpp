#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int c,n,a[1001],p,s;
	double g;
	cout<<showpoint<<fixed;
	for (cin>>c;c;c--) {
		cin>>n;
		s=0;
		for (p=1;p<=n;p++) {
			cin>>a[p];
			s+=a[p];
		}
		g=(double) s/n;
		s=0;
		for (p=1;p<=n;p++) {
			if (a[p]>g) s++;
		}
		g=(double) 100*s/n;
		cout<<setprecision(3)<<g<<"%"<<endl;
	}
}