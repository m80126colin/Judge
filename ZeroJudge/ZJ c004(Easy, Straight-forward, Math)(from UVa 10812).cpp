#include <iostream>
using namespace std;

int main() {
	int s,d,t;
	for (cin>>t;t;t--) {
		cin>>s>>d;
		if (d>s) cout<<"impossible";
		else {
			if ((s%2&&d%2)||(s%2==0&&d%2==0)) cout<<(s+d)/2<<" "<<(s-d)/2;
			else cout<<"impossible";
		}
		cout<<endl;
	}
}