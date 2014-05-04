#include <iostream>
using namespace std;

int main() {
	int a,b,c,i;
	while (cin>>a&&a) {
		b=1;
		for (i=2;i*i<=a;i++) {
			if (a%i==0) {
				b+=i;
				if (i!=a/i) b+=a/i;
			}
		}
		if (a==b) cout<<"="<<b<<endl;
		else {
			c=1;
			for (i=2;i*i<=b;i++) {
				if (b%i==0) {
					c+=i;
					if (i!=b/i) c+=b/i;
				}
			}
			if (a==c) cout<<b<<endl;
			else cout<<0<<endl;
		}
	}
}