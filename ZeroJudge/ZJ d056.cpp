#include <iostream>
using namespace std;

int main() {
	static int a[1000001],i,j,b;
	for (cin>>a[0];a[0];a[0]--) {
		for (cin>>i,j=1;j<=i;j++) {
			cin>>a[j]>>b;
			a[j]+=b;
		}
		for (j=i;j>1;j--) {
			if (a[j]/10) {
				a[j-1]+=a[j]/10;
				a[j]%=10;
			}
		}
		for (j=1;j<=i;j++) cout<<a[j];
		cout<<endl;
	}
}