#include <iostream>
using namespace std;

int main() {
	short n,t,x,x1,x2,p;
	for (cin>>t;t;t--) {
		x1=x2=p=0;
		for (cin>>n;p<n;p++) {
			cin>>x;
			if (p==0||x<x1) x1=x;
			if (x>=x2) x2=x;
		}
		cout<<2*(x2-x1)<<endl;
	}
}