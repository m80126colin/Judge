#include <iostream>
using namespace std;

long long b[37],c[36];

long long f(long long x,long long y) {
	if (!x) return 0;
	return f(x/y,y)+c[x%y];
}

int main() {
	long long t,n,i,j,m;
	for (cin>>n,t=1;t<=n;t++) {
		if (t>1) cout<<endl;
		cout<<"Case "<<t<<":\n";
		for (i=0;i<36;i++) cin>>c[i];
		for (cin>>j;j;j--) {
			int k;
			cin>>k;
			cout<<"Cheapest base(s) for number "<<k<<":";
			b[2]=f(k,2),m=b[2];
			for (i=3;i<=36;i++) {
				b[i]=f(k,i);
				m=min(m,b[i]);
			}
			for (i=2;i<=36;i++) {
				if (m==b[i]) cout<<" "<<i;
			}
			cout<<endl;
		}
	}
}