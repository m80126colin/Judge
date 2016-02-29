#include <iostream>
#include <string>
using namespace std;

int main() {
	char z;
	string n;
	int t,i,j,a[26];
	for (i=0;i<26;i++) a[i]=0;
	j=0;
	cin>>t;
	for (cin.ignore(1);t;t--) {
		getline(cin,n);
		for (i=0;i<n.size();i++) {
			if (n[i]>='A'&&n[i]<='Z') {
				a[n[i]-65]++;
				j=max(a[n[i]-65],j);
			}
			if (n[i]>='a'&&n[i]<='z') {
				a[n[i]-97]++;
				j=max(a[n[i]-97],j);
			}
		}
	}
	for (j;j;j--) {
		for (i=0;i<26;i++) {
			if (j==a[i]) {
				z=i+65;
				cout<<z<<" "<<a[i]<<endl;
			}
		}
	}
}