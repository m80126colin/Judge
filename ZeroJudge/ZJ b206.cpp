#include <iostream>
#include <string>
using namespace std;

int main() {
	int i,t,m,n;
	bool ox,ox2;
	string a,b;
	for (cin>>t;t;t--) {
		ox=ox2=0;
		cin>>a>>b;
		if (a.size()==b.size()) ox=1;
		if (b.size()>=5) ox2=1;
		m=n=0;
		for (i=0;i<a.size();i++) {
			if (a[i]=='O') m++;
			if (i<b.size()&&b[i]=='O') n++;
		}
		if (ox&&ox2) {
			if (m>n) cout<<"A";
			else if (m<n) cout<<"B";
			else cout<<"NO";
		}
		else {
			if (ox2) {
				if (m>n) cout<<"NO";
				else if (m<n) cout<<"B";
				else cout<<"NO";
			}
			else {
				if (m>n+5-b.size()) cout<<"A";
				else if (m+5-a.size()<n) cout<<"B";
				else cout<<"NO";
			}
		}
		cout<<endl;
	}
}