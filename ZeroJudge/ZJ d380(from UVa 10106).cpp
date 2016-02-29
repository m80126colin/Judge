#include <iostream>
#include <string>
using namespace std;

string n;	
int x[252],y[252],c[501],t1,t2;

int num(int z[]) {
	for (x[0]=1;x[0]<=n.size();x[0]++) {
		y[0]=n.size()-x[0];
		z[x[0]]=n[y[0]]-48;
	}
	return 0;
}

int main() {
	while (cin>>n) {
		t1=n.size();
		num(x);
		cin>>n;
		t2=n.size();
		num(y);
		for (x[0]=0;x[0]<=500;x[0]++) c[x[0]]=0;
		for (x[0]=0;x[0]<t1;x[0]++) {
			for (y[0]=0;y[0]<t2;y[0]++) {
				c[x[0]+y[0]]+=(x[x[0]+1]*y[y[0]+1]);
				c[x[0]+y[0]+1]+=(c[x[0]+y[0]]/10);
				c[x[0]+y[0]]%=10;
			}
		}
		y[0]=0;
		for (x[0]=500;x[0]>=0;x[0]--) {
			if ((c[x[0]]!=0)||(y[0]&&c[x[0]]==0)||(x[0]==0)) {
				cout<<c[x[0]];
				y[0]=1;
			}
		}
		cout<<endl;
	}
}