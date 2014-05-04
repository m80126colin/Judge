#include <iostream>
#include <iomanip>
using namespace std;

int a,y[9],q[9][9];

int queen(int x) {
	int i,b;
	if (x<9) {
		for (y[x]=1;y[x]<=8;y[x]++) {
			for (i=1;i<x;i++) {
				if (y[x]==y[i]||abs(y[x]-y[i])==x-i) break;
			}
			if (x==i) queen(x+1);
		}
	}
	else {
		b=0;
		for (i=1;i<=8;i++) b+=q[i][y[i]];
		a=max(a,b);
		return 0;
	}
}

int main() {
	int k,i,j;
	for (cin>>k;k;k--) {
		for (i=1;i<=8;i++) {
			for (j=1;j<=8;j++) cin>>q[i][j];
		}
		a=0;
		queen(1);
		cout<<fixed<<setw(5)<<a<<endl;
	}
}