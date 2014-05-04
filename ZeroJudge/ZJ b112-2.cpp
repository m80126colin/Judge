#include <iostream>
#include <math.h>
using namespace std;

int gcd(int x,int y) {
	if (x%y) return gcd(y,x%y);
	else return y;
}

int main() {
	int n,a[501],i;
	while (cin>>n) {
		cin>>a[0];
		for (i=2;i<=n;i++) {
			cin>>a[i];
			a[0]=gcd(max(a[0],a[i]),min(a[0],a[i]));
		}
		cout<<a[0]<<endl;
	}
}