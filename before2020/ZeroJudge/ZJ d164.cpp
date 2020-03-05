#include <iostream>
using namespace std;

int main() {
	int n[10001],m,max,t,i,j;
	while (cin>>n[0]>>m) {
		t=max=0;
		for (i=1;i<=n[0];i++) cin>>n[i];
		for (i=j=1;i<n[0]+m;i++) {
			if (i<=m) t+=n[i];
			else {
				if (t>max) max=t;
				t-=n[j];
				j++;
				if (i<=n[0]) t+=n[i];
				else t+=n[i-n[0]];
			}
		}
		if (t>max) max=t;
		cout<<max<<endl;
	}
}