#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int n[50],c,p,i,j;

int re(int x,int y) {
	if (x%y) re(y,x%y);
	else if (y==1) p++;
	return 0;
}

int main() {
	while (cin>>n[0]&&n[0]) {
		c=p=0;
		c=n[0]*(n[0]-1)/2;
		for (i=1;i<=n[0];i++) cin>>n[i];
		for (i=1;i<n[0];i++) {
			for (j=i+1;j<=n[0];j++) re(max(n[i],n[j]),min(n[i],n[j]));
		}
		if (p) {
			cout<<fixed<<setprecision(6)<<pow(6.0*c/p,0.5)<<endl;
		}
		else cout<<"No estimate for this data set."<<endl;
	}
}