#include <iostream>
using namespace std;

int main() {
	int t,g,l;
	for (cin>>t;t;t--) {
		cin>>g>>l;
		if (l%g) cout<<"-1"<<endl;
		else {
			l=l/g;
			cout<<g<<" "<<g*l<<endl;
		}
	}
}