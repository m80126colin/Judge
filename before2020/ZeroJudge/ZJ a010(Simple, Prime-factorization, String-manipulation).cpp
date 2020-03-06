/**
 *  @judge ZeroJudge
 *  @id a010
 *  @tag Simple, Prime factorization, String Manipulation
 */
#include <iostream>
using namespace std;

int n,m,t[168],p[168];

int prime(int x) {
	int y;
	for (y=x-1;x>1;y--) {
		if (x%y==0) break;
	}
	if (y==1) p[n++]=x;
	return 0;
}

int main() {
	p[0]=2,p[1]=3;
	n=2;
	for (m=6;m<1000;m+=6) {
		prime(m-1);
		prime(m+1);
	}
	while (cin>>n) {
		if (n==1) cout<<1;
		for (m=0;n>=p[m]&&m<168;m++) {
			for (t[m]=0;n%p[m]==0;n/=p[m]) t[m]++;
			if (t[m]) {
				cout<<p[m];
				if (t[m]>1) cout<<"^"<<t[m];
				if (n!=1) cout<<" * ";
			}
		}
		if (n!=1) cout<<n;
		cout<<endl;
	}
}