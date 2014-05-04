#include <iostream>
using namespace std;

int main() {
	int a[11],b,i,j,t;
	while (cin>>a[0]>>b&&(a[0]||b)) {
		t=j=0;
		for (i=1;i<11;i++) {
			a[i]=a[0]%10+b%10+j;
			if (a[i]>=10) t++;
			j=a[i]/10;
			a[i]%=10;
			a[0]/=10;
			b/=10;
		}
		if (t>1) cout<<t<<" carry operations."<<endl;
		else cout<<( (t) ? "1" : "No" )<<" carry operation."<<endl;
	}
}