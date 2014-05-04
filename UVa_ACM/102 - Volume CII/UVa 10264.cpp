#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int n,s,i,j,m;
	static int x[20000],y[20000];
	while (cin>>n) {
		s=(double) pow(2.0,n)+0.5;
		for (i=0;i<s;i++) scanf("%d",&x[i]);
		memset(y,0,sizeof(y));
		for (i=0;i<s;i++) {
			for (j=0;j<n;j++) y[i]+=x[i^(1<<j)];
		}
		m=0;
		for (i=0;i<s;i++) {
			for (j=0;j<n;j++) {
				m=max(m,y[i]+y[i^(1<<j)]);
			}
		}
		cout<<m<<endl;
	}
}