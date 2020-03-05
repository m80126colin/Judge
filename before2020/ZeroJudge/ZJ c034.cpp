#include <iostream>
#include <string>
using namespace std;

int main() {
	bool ox;
	string n;
	int a[105],b[105];
	ox=0;
	for (a[0]=104;a[0];a[0]--) a[a[0]]=0;
	while (cin>>n&&n!="0") {
		for (a[0]=1;a[0]<=n.size();a[0]++) {
			b[a[0]]=n[n.size()-a[0]]-48;
			a[a[0]]+=b[a[0]];
		}
	}
	for (a[0]=1;a[0]<=104;a[0]++) {
		if (a[a[0]]/10) {
			a[a[0]+1]+=a[a[0]]/10;
			a[a[0]]%=10;
		}
	}
	for (a[0]=104;a[0];a[0]--) {
		if (ox||(ox==0&&a[a[0]])||(ox==0&&a[0]==1)) {
			ox=1;
			cout<<a[a[0]];
		}
	}
	cout<<endl;
}