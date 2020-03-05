#include <iostream>
using namespace std;

int main() {
	bool ox;
	int m,n,i,j,t,a[1001],b[1001];
	while (cin>>m>>n&&n) {
		ox=1;
		cout<<".";
		t=1;
		for (i=1,m*=10;ox;i++,m*=10) {
			b[i]=m/n;
			a[i]=m=m%n;
			if (m==0) {
				if (t==50) cout<<endl;
				t=1;
				cout<<b[i]<<"\nThis expansion terminates.\n";
				ox=0;
				continue;
			}
			for (j=1;j<i;j++) {
				if (a[j]==a[i]) {
					if (b[i]!=b[j]) {
						if (t==50) cout<<endl;
						cout<<b[i];
						t=1;
					}
					cout<<"\nThe last "<<i-j<<" digits repeat forever.\n";
					ox=0;
					break;
				}
			}
			if (t==50) {
				cout<<endl;
				t=0;
			}
			if (ox) {
				cout<<b[i];
				t++;
			}
		}
	}
}