#include <iostream>
#include <string>
using namespace std;

int main() {
	char a;
	string n;
	int b[128],t,i;
	for (b[0]=127;b[0];b[0]--) b[b[0]]=0;
	cin>>t;
	for (cin.ignore(1);t;t--) {
		getline(cin,n);
		for (i=0;i<n.size();i++) {
			if (n[i]>='A'&&n[i]<='Z') b[n[i]]++;
			if (n[i]>='a'&&n[i]<='z') b[n[i]-=32]++;
			b[0]=max(b[0],b[n[i]]);
		}
	}
	for (b[0];b[0];b[0]--) {
		for (i=65;i<91;i++) {
			if (b[0]==b[i]) {
				a=i;
				cout<<a<<" "<<b[i]<<endl;
			}
		}
	}
}