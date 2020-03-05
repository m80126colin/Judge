#include <iostream>
using namespace std;

int main() {
	unsigned long long x,y,m;
	while (cin>>x>>y>>x>>y>>m) {
		x=(x+y+m)/2+1;
		if (x<y) cout<<"Must be a loser."<<endl;
		else cout<<x-y<<endl;
	}
}