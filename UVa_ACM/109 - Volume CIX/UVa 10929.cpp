#include <iostream>
#include <string>
using namespace std;

int main() {
	string n;
	short i,a,b;
	while (cin>>n&&n!="0") {
		for (a=b=i=0;i<n.size();i++) {
			if (i%2) a+=n[i]-48;
			else b+=n[i]-48;
		}
		if ((a-b)%11) cout<<n<<" is not a multiple of 11.\n";
		else cout<<n<<" is a multiple of 11.\n";
	}
}