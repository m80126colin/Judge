#include <iostream>
using namespace std;

int main() {
	int k,a,b,c;
	for (cin>>k;k;k--) {
		scanf("%d %d %d",&a,&b,&c);
		if (a!=b&&b!=c&&a!=c) cout<<"YES\n";
		else cout<<"NO\n";
	}
}