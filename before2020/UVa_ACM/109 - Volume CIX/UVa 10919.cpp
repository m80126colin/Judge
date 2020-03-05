#include <iostream>
using namespace std;

int main() {
	bool yn;
	int k[101],m,c[101],r,t,s,g;
	for (cin>>k[0];k[0]!=0;cin>>k[0]) {
		cin>>m;
		for (t=1;t<=k[0];t++) cin>>k[t];
		yn=true;
		while (m--) {
			cin>>c[0]>>r;
			g=0;
			for (t=1;t<=c[0];t++) {
				cin>>c[t];
				for (s=1;s<=k[0];s++) {
					if (k[s]==c[t]) g++;
				}
			}
			if (g<r) yn=false;
		}
		if (yn) cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
}