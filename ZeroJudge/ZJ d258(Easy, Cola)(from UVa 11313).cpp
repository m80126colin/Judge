#include <iostream>
using namespace std;

int main() {
	int n,m,t;
	for (cin>>t;t;t--) {
		cin>>n>>m;
		n--,m--;
		if (n%m) cout<<"cannot do this\n";
		else cout<<n/m<<endl;
	}
}