#include <iostream>
#include <string>
using namespace std;

int m,n,a[1001];
string s[1001];

int money(string x) {
	int y;
	for (y=1;y<=m;y++) {
		if (x==s[y]) {
			a[0]+=a[y];
			return 0;
		}
	}
	return 0;
}

int main() {
	cin>>m>>n;
	for (a[0]=1;a[0]<=m;a[0]++) cin>>s[a[0]]>>a[a[0]];
	while (n--) {
		a[0]=0;
		while (cin>>s[0]&&(s[0]!=".")) money(s[0]);
		cout<<a[0]<<endl;
	}
}